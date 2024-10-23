#include <cstdio>
#include <cstring>

#define ALIGNMENT 4096 /*must be a power 2*/
void dmi_fread(FILE* file, uint64_t offset, void* buffer, size_t bytes);

// Implement the fread function using dmi_fread.
// Reading from offsets and number of bytes 
constexpr uint64_t align_floor(uint64_t offset, uint64_t alignment /*must be a power 2*/) {
    return offset & ~(alignment - 1);
}

constexpr uint64_t align_ceil(uint64_t offset, uint64_t alignment /*must be a power 2*/) {
    return (offset + alignment - 1) & ~(alignment - 1);
}

void fread(FILE* file, uint64_t offset, void* buffer, size_t bytes) {
    uint64_t aligned_offset = align_floor(offset, ALIGNMENT);
    size_t discard_start_bytes = offset - aligned_offset;
    uint64_t end_offset = offset + bytes;
    uint64_t aligned_end_offset = align_ceil(end_offset, ALIGNMENT);
    size_t discard_end_bytes = aligned_end_offset - end_offset;

    size_t aligned_total_bytes = aligned_end_offset - aligned_offset;
/** IF I can allocate a buffer larger than the supplied buffer ----
    char *aligned_buffer = (char *)aligned_alloc(4096, aligned_total_bytes * sizeof (char));

    dmi_fread(file, aligned_offset, aligned_buffer, aligned_total_bytes);
    memcpy(buffer, aligned_buffer + discard_start_bytes, bytes);
*/
    char *aligned_buffer = (char *)aligned_alloc(ALIGNMENT, ALIGNMENT * sizeof (char));
    char *dest = (char*)buffer;
    for(uint64_t ofst = aligned_offset; ofst < aligned_end_offset; ofst += ALIGNMENT) {
        dmi_fread(file, aligned_offset, aligned_buffer, ALIGNMENT);
        if (discard_start_bytes > 0) {
            memcpy(dest, aligned_buffer + discard_start_bytes, ALIGNMENT-discard_start_bytes);
            dest += ALIGNMENT-discard_start_bytes;
            discard_start_bytes = 0;
        } else if (discard_end_bytes > 0 && ofst == aligned_end_offset-ALIGNMENT) {
            memcpy(buffer, aligned_buffer, ALIGNMENT-discard_end_bytes);
            dest += ALIGNMENT-discard_end_bytes;
            discard_end_bytes = 0;
        } else {
            memcpy(buffer, aligned_buffer, ALIGNMENT);
            dest += ALIGNMENT;
        }
    }
    
    free(aligned_buffer);

}