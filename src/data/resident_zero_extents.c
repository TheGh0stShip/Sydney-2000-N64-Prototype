/* Discontinuous explicitly initialized zero extents in resident .data. */
typedef unsigned char u8;

#define ZERO_EXTENT(name, section_name, size) \
    u8 name[size] __attribute__((section(section_name))) = {0}

ZERO_EXTENT(zero_80038C40, ".data.zero_80038C40", 43568);
ZERO_EXTENT(zero_80043714, ".data.zero_80043714", 1756);
ZERO_EXTENT(zero_80043EF4, ".data.zero_80043EF4", 1740);
ZERO_EXTENT(zero_8004460C, ".data.zero_8004460C", 4260);
ZERO_EXTENT(zero_800456B4, ".data.zero_800456B4", 8544);
ZERO_EXTENT(zero_8005AA04, ".data.zero_8005AA04", 256);
ZERO_EXTENT(zero_8005AB74, ".data.zero_8005AB74", 276);
ZERO_EXTENT(zero_8005ACA8, ".data.zero_8005ACA8", 19708);
ZERO_EXTENT(zero_8005FA34, ".data.zero_8005FA34", 9920);
ZERO_EXTENT(zero_80062120, ".data.zero_80062120", 788);
ZERO_EXTENT(zero_800624B0, ".data.zero_800624B0", 4208);
ZERO_EXTENT(zero_80063F34, ".data.zero_80063F34", 2052);
ZERO_EXTENT(zero_8006473C, ".data.zero_8006473C", 2148);
ZERO_EXTENT(zero_8006504C, ".data.zero_8006504C", 428);
ZERO_EXTENT(zero_800661D0, ".data.zero_800661D0", 1152);
