
void naive(int *src, int *dst, int SIZE)
{
    for(int i=0; i < SIZE; i++)
        for(int j=0; j < SIZE; j++)
            dst[(j * SIZE) + i] = src[(i * SIZE) + j];
}

void aware(int *src, int *dst, int SIZE)
{
    //change t for different speed-ups
    int t = 8;
    
    for (int i = 0; i < SIZE; i += t) {
        for (int j = 0; j < SIZE; j += t) {
            for (int k = i; k < i + t; ++k) {
                for (int l = j; l < j + t; ++l) {
                    dst[k + l*SIZE] = src[l + k*SIZE];
                }
            }
        }
    }
}

uint32_t morton_decode(uint32_t z)
{
    z = z & 0x55555555;
    z = (z | (z >> 1)) & 0x33333333;
    z = (z | (z >> 2)) & 0x0F0F0F0F;
    z = (z | (z >> 4)) & 0x00FF00FF;
    z = (z | (z >> 8)) & 0x0000FFFF;
    return z;
}

void oblivious(int *src, int *dst, int SIZE)
{
    for(uint32_t z=0; z < SIZE*SIZE; z++)
    {
        uint32_t x = morton_decode(z);
        uint32_t y = morton_decode(z >> 1);
        
        dst[(y * SIZE) + x] = src[(x * SIZE) + y];
        
    }
}

void optimized(int *src, int *dst, int SIZE)
{
    //change t for different speed-ups
    int t = 8;
    
    for (int z = 0; z < SIZE*SIZE; z += t*t) {
        
        uint32_t i = morton_decode(z);
        uint32_t j = morton_decode(z >> 1);
        
        for (int k = i; k < i + t; ++k) {
            for (int l = j; l < j + t; ++l) {
                dst[k + l*SIZE] = src[l + k*SIZE];
            }
        }
    }
}
