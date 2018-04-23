/* $FreeBSD: releng/11.1/sys/dev/syscons/logo/logo.c 206363 2010-04-07 17:07:06Z jkim $ */

#define	LOGO_WIDTH	66
#define	LOGO_HEIGHT	69

unsigned int logo_w = LOGO_WIDTH;
unsigned int logo_h = LOGO_HEIGHT;

unsigned char logo_pal[256 * 3] = {
	0x00, 0x00, 0x00,
	0x0b, 0x00, 0x00,
	0x0b, 0x0b, 0x0b,
	0x13, 0x01, 0x01,
	0x1b, 0x05, 0x04,
	0x13, 0x13, 0x13,
	0x1b, 0x1b, 0x1b,
	0x1c, 0x15, 0x14,
	0x25, 0x03, 0x01,
	0x33, 0x0e, 0x0c,
	0x23, 0x21, 0x1a,
	0x23, 0x23, 0x23,
	0x2b, 0x2b, 0x2b,
	0x3c, 0x3c, 0x3c,
	0x34, 0x32, 0x32,
	0x35, 0x30, 0x2a,
	0x58, 0x00, 0x00,
	0x4c, 0x0f, 0x0d,
	0x47, 0x24, 0x15,
	0x6c, 0x01, 0x01,
	0x66, 0x09, 0x09,
	0x66, 0x17, 0x15,
	0x74, 0x01, 0x00,
	0x7b, 0x00, 0x00,
	0x77, 0x09, 0x08,
	0x79, 0x19, 0x17,
	0x6e, 0x3e, 0x3e,
	0x76, 0x35, 0x35,
	0x72, 0x2b, 0x26,
	0x65, 0x2a, 0x20,
	0x5a, 0x4f, 0x32,
	0x44, 0x44, 0x44,
	0x4b, 0x4a, 0x4a,
	0x57, 0x56, 0x56,
	0x56, 0x4d, 0x4c,
	0x77, 0x45, 0x45,
	0x6d, 0x5d, 0x4f,
	0x6c, 0x6c, 0x6c,
	0x62, 0x62, 0x62,
	0x76, 0x75, 0x75,
	0x72, 0x67, 0x55,
	0x84, 0x00, 0x00,
	0x8b, 0x00, 0x00,
	0x88, 0x0c, 0x0b,
	0x89, 0x18, 0x17,
	0x93, 0x00, 0x00,
	0x9b, 0x00, 0x00,
	0x99, 0x0a, 0x06,
	0x95, 0x17, 0x16,
	0x95, 0x11, 0x0c,
	0x87, 0x2a, 0x29,
	0x99, 0x29, 0x27,
	0x98, 0x37, 0x37,
	0x86, 0x39, 0x34,
	0xa4, 0x00, 0x00,
	0xab, 0x00, 0x00,
	0xab, 0x0c, 0x01,
	0xa7, 0x0b, 0x06,
	0xa8, 0x13, 0x0a,
	0xa6, 0x16, 0x15,
	0xb3, 0x00, 0x00,
	0xbb, 0x00, 0x00,
	0xb7, 0x0a, 0x03,
	0xb3, 0x12, 0x00,
	0xba, 0x15, 0x03,
	0xb5, 0x18, 0x17,
	0xb7, 0x27, 0x03,
	0xb9, 0x27, 0x18,
	0xa8, 0x2a, 0x16,
	0xa8, 0x26, 0x25,
	0xb9, 0x2a, 0x29,
	0xb6, 0x39, 0x37,
	0xab, 0x35, 0x2f,
	0xae, 0x4c, 0x36,
	0x93, 0x5d, 0x39,
	0x90, 0x4e, 0x4b,
	0x91, 0x67, 0x56,
	0x8a, 0x75, 0x70,
	0xa8, 0x49, 0x47,
	0xb4, 0x5a, 0x58,
	0xb2, 0x53, 0x4b,
	0xac, 0x71, 0x53,
	0xb8, 0x7a, 0x78,
	0xb2, 0x65, 0x64,
	0xc3, 0x01, 0x00,
	0xc3, 0x0a, 0x00,
	0xcb, 0x00, 0x00,
	0xca, 0x0b, 0x00,
	0xc7, 0x08, 0x08,
	0xc5, 0x13, 0x00,
	0xcb, 0x12, 0x00,
	0xcb, 0x1a, 0x01,
	0xc3, 0x18, 0x05,
	0xc9, 0x17, 0x14,
	0xd3, 0x00, 0x00,
	0xd2, 0x0b, 0x00,
	0xdb, 0x00, 0x00,
	0xd8, 0x0c, 0x05,
	0xd3, 0x14, 0x00,
	0xd3, 0x1b, 0x01,
	0xdb, 0x1c, 0x01,
	0xd9, 0x14, 0x03,
	0xd5, 0x18, 0x15,
	0xc8, 0x25, 0x01,
	0xd4, 0x23, 0x02,
	0xd3, 0x2b, 0x01,
	0xdb, 0x22, 0x01,
	0xdb, 0x2a, 0x01,
	0xd5, 0x27, 0x1c,
	0xd6, 0x33, 0x02,
	0xdb, 0x33, 0x02,
	0xda, 0x3a, 0x03,
	0xd4, 0x3c, 0x1a,
	0xc8, 0x33, 0x17,
	0xca, 0x29, 0x24,
	0xc8, 0x32, 0x2b,
	0xd3, 0x35, 0x2d,
	0xe3, 0x00, 0x00,
	0xeb, 0x00, 0x00,
	0xea, 0x0b, 0x00,
	0xe5, 0x18, 0x03,
	0xf1, 0x03, 0x00,
	0xf4, 0x0b, 0x00,
	0xf4, 0x17, 0x01,
	0xe2, 0x24, 0x01,
	0xe3, 0x2a, 0x01,
	0xe9, 0x2c, 0x02,
	0xea, 0x28, 0x07,
	0xe3, 0x33, 0x01,
	0xe3, 0x3b, 0x02,
	0xea, 0x33, 0x02,
	0xeb, 0x3c, 0x02,
	0xe9, 0x3c, 0x09,
	0xf4, 0x25, 0x04,
	0xf3, 0x34, 0x0e,
	0xed, 0x35, 0x29,
	0xd9, 0x45, 0x0b,
	0xd7, 0x43, 0x14,
	0xc8, 0x40, 0x19,
	0xd7, 0x56, 0x3a,
	0xcf, 0x46, 0x34,
	0xec, 0x43, 0x03,
	0xeb, 0x4c, 0x04,
	0xe4, 0x47, 0x05,
	0xe9, 0x58, 0x17,
	0xf0, 0x47, 0x03,
	0xf1, 0x4f, 0x11,
	0xee, 0x4a, 0x2d,
	0xee, 0x6d, 0x19,
	0xee, 0x6c, 0x34,
	0xcf, 0x66, 0x33,
	0xc9, 0x4b, 0x49,
	0xc6, 0x57, 0x57,
	0xdb, 0x55, 0x4a,
	0xd7, 0x58, 0x52,
	0xcf, 0x4e, 0x49,
	0xd3, 0x69, 0x54,
	0xc9, 0x69, 0x67,
	0xc9, 0x77, 0x76,
	0xda, 0x7a, 0x77,
	0xd3, 0x72, 0x6d,
	0xf5, 0x59, 0x4c,
	0xed, 0x71, 0x51,
	0xe5, 0x74, 0x65,
	0xef, 0x76, 0x6e,
	0xb6, 0x8c, 0x6b,
	0xa4, 0x8c, 0x63,
	0xf2, 0x98, 0x28,
	0xf2, 0x92, 0x36,
	0xf3, 0xa8, 0x2b,
	0xf6, 0xb4, 0x35,
	0xed, 0xaa, 0x34,
	0xdb, 0x95, 0x2c,
	0xf1, 0x8f, 0x52,
	0xfa, 0x87, 0x67,
	0xfa, 0x97, 0x75,
	0xef, 0x8e, 0x73,
	0xf2, 0xb1, 0x4f,
	0xf5, 0xa6, 0x79,
	0xf0, 0xae, 0x71,
	0xd1, 0x88, 0x76,
	0xf6, 0xcc, 0x69,
	0xfc, 0xe9, 0x76,
	0x89, 0x89, 0x89,
	0x98, 0x97, 0x97,
	0x90, 0x8f, 0x8f,
	0xb3, 0x94, 0x89,
	0xa6, 0xa6, 0xa5,
	0xb8, 0xb8, 0xb8,
	0xb2, 0xa8, 0xa6,
	0xc3, 0x8c, 0x8b,
	0xd5, 0x88, 0x87,
	0xd7, 0x99, 0x98,
	0xcd, 0x9a, 0x9a,
	0xd0, 0xa6, 0x93,
	0xc6, 0xaa, 0xa4,
	0xd5, 0xa7, 0xa7,
	0xd9, 0xb8, 0xb6,
	0xc6, 0xb9, 0xb5,
	0xfa, 0x9a, 0x8a,
	0xef, 0x94, 0x8d,
	0xed, 0xa6, 0x93,
	0xf7, 0xa7, 0x86,
	0xf5, 0xa9, 0x98,
	0xf6, 0xb7, 0x87,
	0xf6, 0xb5, 0x97,
	0xec, 0xab, 0x93,
	0xe5, 0xa7, 0xa6,
	0xe2, 0xb4, 0xb4,
	0xfa, 0xac, 0xa3,
	0xf3, 0xb6, 0xa6,
	0xfa, 0xba, 0xb5,
	0xe8, 0xb6, 0xac,
	0xf5, 0xc2, 0x94,
	0xfa, 0xc7, 0xa8,
	0xf8, 0xc7, 0xba,
	0xfa, 0xd4, 0xab,
	0xf9, 0xd5, 0xb8,
	0xeb, 0xc5, 0xb1,
	0xfd, 0xea, 0x8b,
	0xfd, 0xeb, 0xba,
	0xfd, 0xef, 0xae,
	0xd2, 0xc7, 0xbf,
	0xca, 0xc8, 0xc7,
	0xd5, 0xc7, 0xc7,
	0xd7, 0xd6, 0xd6,
	0xd3, 0xd1, 0xc4,
	0xea, 0xc6, 0xc6,
	0xec, 0xd3, 0xd3,
	0xe8, 0xda, 0xd9,
	0xf8, 0xca, 0xc8,
	0xfa, 0xd8, 0xc7,
	0xf1, 0xd5, 0xd4,
	0xf3, 0xda, 0xda,
	0xfb, 0xdb, 0xd3,
	0xfb, 0xdd, 0xdb,
	0xf8, 0xd7, 0xd5,
	0xef, 0xde, 0xc8,
	0xfb, 0xe4, 0xcd,
	0xfc, 0xe8, 0xc9,
	0xfc, 0xe4, 0xdc,
	0xfb, 0xeb, 0xdb,
	0xf8, 0xe6, 0xd6,
	0xfd, 0xf7, 0xcb,
	0xf1, 0xe9, 0xd9,
	0xe9, 0xe6, 0xe6,
	0xfa, 0xe4, 0xe3,
	0xfb, 0xeb, 0xe3,
	0xfa, 0xec, 0xea,
	0xf4, 0xe7, 0xe4,
	0xfc, 0xf1, 0xe3,
	0xfc, 0xf2, 0xec,
	0xf4, 0xf4, 0xf4,
	0xfc, 0xf4, 0xf2,
	0xfd, 0xf9, 0xf5,
	0xfd, 0xfc, 0xfb
};

unsigned char logo_img[LOGO_WIDTH * LOGO_HEIGHT] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x02, 0x02,
	0x02, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x0b,
	0x0b, 0x06, 0x06, 0x06, 0x05, 0x05, 0x02, 0x02,
	0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x10, 0x2c, 0x48, 0x47, 0x33,
	0x14, 0x09, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x05, 0x05,
	0x06, 0x0b, 0x0c, 0x1f, 0x21, 0x25, 0xb7, 0xb9,
	0xb8, 0xb8, 0xb9, 0xb9, 0x27, 0x26, 0x20, 0x0d,
	0x0c, 0x06, 0x06, 0x05, 0x02, 0x02, 0x02, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x08, 0x11, 0x2c, 0x45, 0x44, 0x31, 0x18, 0x09,
	0x00, 0x00, 0x00, 0x00, 0x13, 0x2b, 0x45, 0x47,
	0xa0, 0xc8, 0xc8, 0x9c, 0x47, 0x15, 0x08, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x05, 0x06,
	0x0b, 0x0d, 0x26, 0xb8, 0xbc, 0xe1, 0xf5, 0xfc,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,
	0xf5, 0xdf, 0xbb, 0xb7, 0x21, 0x0e, 0x0b, 0x05,
	0x05, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x01,
	0x11, 0x35, 0x9a, 0xa4, 0xa4, 0x9f, 0x97, 0x3a,
	0x2a, 0x16, 0x08, 0x00, 0x00, 0x04, 0x2a, 0x29,
	0x31, 0x45, 0x97, 0xc8, 0xe6, 0xd3, 0xc7, 0xb0,
	0x9c, 0x1c, 0x08, 0x00, 0x02, 0x02, 0x05, 0x06,
	0x0c, 0x21, 0xb8, 0xe1, 0xfc, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf5, 0xbc,
	0x27, 0x1f, 0x0c, 0x06, 0x02, 0x02, 0x00, 0x01,
	0x12, 0x50, 0xb0, 0xd1, 0xd3, 0xd3, 0xd2, 0x9f,
	0x46, 0x2f, 0x29, 0x2a, 0x10, 0x00, 0x00, 0x08,
	0x2e, 0x29, 0x2a, 0x3a, 0x43, 0x9b, 0xd4, 0xf8,
	0xec, 0xd3, 0xd1, 0xc7, 0xa3, 0x1c, 0x0a, 0x0a,
	0x0c, 0x26, 0xbc, 0xf5, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xfd, 0xfe,
	0xff, 0xff, 0xfc, 0xe1, 0xb7, 0x1f, 0x0c, 0x06,
	0x12, 0x51, 0xd2, 0xed, 0xec, 0xec, 0xf6, 0xeb,
	0xcf, 0x97, 0x41, 0x2d, 0x29, 0x2d, 0x13, 0x00,
	0x00, 0x03, 0x2e, 0x2a, 0x2a, 0x2e, 0x3a, 0x72,
	0x99, 0xd1, 0xe9, 0xec, 0xd7, 0xd7, 0xd6, 0xd5,
	0xb4, 0x4c, 0xbb, 0xf5, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xfd, 0xe9, 0xe9, 0xe8, 0xe9, 0xe9,
	0xe9, 0xeb, 0xf0, 0xf8, 0xfc, 0xfe, 0xfd, 0xe1,
	0x4d, 0x51, 0xd2, 0xf0, 0xf6, 0xf7, 0xf6, 0xfd,
	0xf6, 0xd1, 0x9a, 0x73, 0x3a, 0x2d, 0x29, 0x2d,
	0x10, 0x00, 0x00, 0x01, 0x2d, 0x2d, 0x29, 0x2d,
	0x39, 0x40, 0x6c, 0xa1, 0xa4, 0xcb, 0xd3, 0xe6,
	0xe6, 0xe7, 0xeb, 0xf4, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xe9, 0xe9,
	0xe8, 0xec, 0xec, 0xe4, 0xcf, 0xc0, 0xc0, 0xda,
	0xe9, 0xd8, 0xd8, 0xfa, 0xfb, 0xfb, 0xf8, 0xfb,
	0xf8, 0xec, 0xd1, 0xa3, 0x8c, 0x41, 0x2f, 0x2a,
	0x29, 0x2e, 0x11, 0x00, 0x00, 0x00, 0x16, 0x36,
	0x29, 0x2d, 0x2e, 0x3c, 0x5d, 0x6c, 0x87, 0xa1,
	0xa4, 0xcb, 0xe7, 0xf8, 0xfc, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xfd, 0xe9, 0xe8, 0xe8, 0xe8, 0xbf, 0x41, 0x3e,
	0x3b, 0x8c, 0xcd, 0xf1, 0xfe, 0xfd, 0xfd, 0xfb,
	0xfb, 0xf0, 0xe6, 0xc7, 0xa4, 0x9a, 0x73, 0x39,
	0x2d, 0x29, 0x2a, 0x3b, 0x08, 0x00, 0x00, 0x00,
	0x11, 0x37, 0x2a, 0x2a, 0x2d, 0x37, 0x3e, 0x61,
	0x87, 0x87, 0xa1, 0xc7, 0xf6, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
	0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xf9, 0xe5, 0xe3, 0x46,
	0x36, 0x3a, 0x8c, 0xd4, 0xfb, 0xff, 0xfe, 0xff,
	0xfd, 0xf8, 0xf0, 0xe6, 0xd1, 0xc8, 0xa4, 0x74,
	0x3e, 0x36, 0x2a, 0x29, 0x3b, 0x30, 0x01, 0x00,
	0x00, 0x00, 0x08, 0x3b, 0x2f, 0x29, 0x2a, 0x36,
	0x3e, 0x58, 0x6c, 0x87, 0xc7, 0xf9, 0xff, 0xff,
	0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
	0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc,
	0xff, 0xff, 0xfd, 0xff, 0xfc, 0xff, 0xfc, 0xf9,
	0xe3, 0x45, 0x39, 0x8c, 0xe7, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xfb, 0xeb, 0xe6, 0xd3, 0xc7, 0xa4,
	0x8c, 0x3e, 0x3c, 0x2f, 0x29, 0x31, 0x47, 0x11,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x41, 0x2a,
	0x29, 0x2f, 0x38, 0x5d, 0x6c, 0xa4, 0xf6, 0xff,
	0xff, 0xff, 0xff, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe,
	0xff, 0xfe, 0xfd, 0xfb, 0xfb, 0xfd, 0xfd, 0xfc,
	0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
	0xfc, 0xff, 0xe9, 0x47, 0x3a, 0xb0, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xfd, 0xf6, 0xec, 0xd3, 0xd1,
	0xc8, 0x8c, 0x58, 0x3e, 0x36, 0x2d, 0x29, 0x45,
	0x47, 0x08, 0x00, 0x00, 0x00, 0x00, 0x02, 0x09,
	0x47, 0x2f, 0x29, 0x2f, 0x3a, 0x41, 0x98, 0xe8,
	0xff, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xfb, 0xfe,
	0xfd, 0xfe, 0xfe, 0xfb, 0xfb, 0xfb, 0xfa, 0xfb,
	0xfb, 0xfb, 0xfd, 0xfd, 0xf8, 0xf8, 0xfd, 0xfd,
	0xf8, 0xfd, 0xf8, 0xf8, 0xf8, 0xc0, 0x97, 0xcc,
	0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xeb, 0xec,
	0xd3, 0xc8, 0x87, 0x5f, 0x3d, 0x37, 0x2f, 0x2a,
	0x30, 0x4f, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x34, 0x46, 0x2b, 0x2b, 0x3b, 0x97,
	0xe3, 0xfd, 0xff, 0xff, 0xfd, 0xf8, 0xfd, 0xfd,
	0xfd, 0xfd, 0xfd, 0xfd, 0xf8, 0xf8, 0xf7, 0xf7,
	0xfa, 0xfa, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8,
	0xf8, 0xf8, 0xfa, 0xf7, 0xf7, 0xfa, 0xf1, 0xe3,
	0xbf, 0xca, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0xf6,
	0xeb, 0xd7, 0xaf, 0x87, 0x60, 0x57, 0x3c, 0x36,
	0x2d, 0x2b, 0x4e, 0x9d, 0x09, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0x12, 0x98, 0x30, 0x2b,
	0x48, 0xc4, 0xfc, 0xff, 0xff, 0xfd, 0xf8, 0xf8,
	0xfd, 0xfd, 0xfb, 0xfb, 0xfd, 0xfd, 0xf8, 0xf8,
	0xf6, 0xf1, 0xf1, 0xf0, 0xf7, 0xf8, 0xf9, 0xf9,
	0xf7, 0xf4, 0xf1, 0xf1, 0xf1, 0xf1, 0xf1, 0xf4,
	0xf9, 0xf0, 0xd0, 0xce, 0xf0, 0xff, 0xff, 0xfd,
	0xfb, 0xeb, 0xd3, 0xa4, 0x87, 0x61, 0x5e, 0x3e,
	0x38, 0x2e, 0x2a, 0x33, 0x9e, 0x34, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x4e,
	0x50, 0x33, 0xbe, 0xf8, 0xfd, 0xff, 0xfd, 0xf8,
	0xf8, 0xfb, 0xfb, 0xfe, 0xfb, 0xfb, 0xfb, 0xf8,
	0xf6, 0xf6, 0xeb, 0xef, 0xef, 0xf0, 0xf6, 0xf6,
	0xeb, 0xf2, 0xef, 0xee, 0xee, 0xef, 0xef, 0xee,
	0xf2, 0xf6, 0xe9, 0xf4, 0xe8, 0xcf, 0xd1, 0xf7,
	0xf0, 0xea, 0xd3, 0xc7, 0xa1, 0x87, 0x78, 0x5f,
	0x55, 0x3c, 0x36, 0x2a, 0x2c, 0x4f, 0x9e, 0x11,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x1d, 0xa0, 0x53, 0xe4, 0xfc, 0xff, 0xfd,
	0xf6, 0xf6, 0xfb, 0xfb, 0xfd, 0xfe, 0xfb, 0xfb,
	0xf8, 0xf6, 0xf6, 0xf6, 0xeb, 0xef, 0xe7, 0xea,
	0xea, 0xe7, 0xe7, 0xe7, 0xd9, 0xef, 0xe7, 0xe7,
	0xe7, 0xea, 0xe9, 0xe9, 0xe9, 0xe9, 0xe4, 0xbf,
	0x97, 0xcb, 0xd2, 0xc7, 0xae, 0xa1, 0x87, 0x78,
	0x61, 0x57, 0x3d, 0x36, 0x2d, 0x2b, 0x4e, 0xbf,
	0x4e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x04, 0x53, 0xe4, 0xf6, 0xfe,
	0xfd, 0xf7, 0xf0, 0xf8, 0xfb, 0xfe, 0xff, 0xff,
	0xfe, 0xfb, 0xf7, 0xf6, 0xeb, 0xec, 0xeb, 0xe7,
	0xe7, 0xe7, 0xe7, 0xd9, 0xd9, 0xd9, 0xd9, 0xd7,
	0xd9, 0xd7, 0xe6, 0xe4, 0xe4, 0xe6, 0xe4, 0xe4,
	0xe4, 0xd0, 0x97, 0x99, 0xca, 0xaf, 0xa1, 0x93,
	0x87, 0x61, 0x57, 0x3d, 0x37, 0x2f, 0x2b, 0x34,
	0x9e, 0xbf, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x27, 0xe5,
	0xf9, 0xff, 0xf7, 0xf2, 0xf7, 0xf7, 0xfb, 0xff,
	0xff, 0xff, 0xfe, 0xfa, 0xf1, 0xf6, 0xec, 0xe6,
	0xe6, 0xe6, 0xd7, 0xd6, 0xd8, 0xd6, 0xd6, 0xd6,
	0xd6, 0xd2, 0xd3, 0xe3, 0xe3, 0xda, 0xe3, 0xd0,
	0xe3, 0xe3, 0xe3, 0xe3, 0xc1, 0x49, 0xa1, 0xa1,
	0xa1, 0x87, 0x77, 0x5f, 0x3e, 0x3e, 0x36, 0x2a,
	0x2c, 0x53, 0xc0, 0x9d, 0x0f, 0x02, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0c,
	0xdf, 0xe8, 0xfd, 0xfb, 0xe7, 0xea, 0xf1, 0xf8,
	0xfe, 0xff, 0xff, 0xff, 0xfe, 0xf1, 0xf0, 0xec,
	0xe6, 0xe6, 0xd7, 0xd6, 0xd6, 0xd2, 0xcd, 0xcd,
	0xcd, 0xcd, 0xcd, 0xd1, 0xcf, 0xcf, 0xcf, 0xcf,
	0xcf, 0xcf, 0xd0, 0xd0, 0xcf, 0xd0, 0xd0, 0xbe,
	0x47, 0x87, 0x87, 0x77, 0x61, 0x3d, 0x3c, 0x2e,
	0x2d, 0x2b, 0x4e, 0xc1, 0xc8, 0xc4, 0x27, 0x02,
	0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x02, 0x25, 0xe5, 0xe9, 0xfe, 0xec, 0xe7, 0xea,
	0xf0, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xee,
	0xe7, 0xe6, 0xd3, 0xd1, 0xcd, 0xcd, 0xca, 0xca,
	0xcb, 0xca, 0xae, 0xa2, 0xa2, 0xa1, 0x99, 0x9b,
	0x9b, 0x9b, 0x97, 0x97, 0x98, 0x9d, 0x9e, 0xbe,
	0xc0, 0xc0, 0x52, 0x48, 0x66, 0x5e, 0x3d, 0x3c,
	0x36, 0x2d, 0x2b, 0x33, 0x9e, 0xcf, 0x9e, 0xe0,
	0xbc, 0x0b, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x06, 0xbc, 0xe4, 0xf8, 0xf6, 0xd7,
	0xd9, 0xea, 0xf0, 0xfb, 0xff, 0xff, 0xff, 0xf7,
	0xee, 0xd9, 0xd7, 0xd3, 0xcb, 0xcc, 0xca, 0xb2,
	0xaf, 0xa2, 0x95, 0x93, 0x86, 0x86, 0x87, 0x72,
	0x72, 0x72, 0x72, 0x72, 0x46, 0x46, 0x46, 0x46,
	0x46, 0x47, 0x4e, 0x53, 0x52, 0x53, 0x48, 0x3e,
	0x3c, 0x36, 0x2e, 0x2a, 0x2c, 0x4f, 0xcf, 0x9d,
	0x52, 0xc6, 0xe1, 0x21, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0xe5, 0xe3, 0xfd,
	0xd7, 0xd4, 0xd9, 0xea, 0xf4, 0xf7, 0xfb, 0xfb,
	0xfa, 0xee, 0xd9, 0xd6, 0xd2, 0xcb, 0xc7, 0xaf,
	0xae, 0xa1, 0x92, 0x86, 0x85, 0x85, 0x7b, 0x66,
	0x66, 0x66, 0x66, 0x5d, 0x5d, 0x5d, 0x41, 0x41,
	0x41, 0x41, 0x41, 0x45, 0x45, 0x48, 0x34, 0x4e,
	0x4b, 0x34, 0x30, 0x2f, 0x2b, 0x2b, 0x4e, 0xbf,
	0x9f, 0x34, 0x53, 0xbd, 0xe1, 0xbb, 0x05, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xb9, 0xe4,
	0xe4, 0xf7, 0xcd, 0xd2, 0xd7, 0xea, 0xf1, 0xfa,
	0xfa, 0xf1, 0xef, 0xd9, 0xd6, 0xcc, 0xc7, 0xaf,
	0xae, 0x93, 0x86, 0x85, 0x85, 0x7b, 0x7a, 0x7b,
	0x77, 0x61, 0x61, 0x58, 0x58, 0x58, 0x58, 0x3e,
	0x3e, 0x3e, 0x3e, 0x3b, 0x3b, 0x3b, 0x3b, 0x30,
	0x33, 0x33, 0x33, 0x4b, 0x35, 0x32, 0x19, 0x2b,
	0x45, 0x73, 0x34, 0x23, 0x4c, 0xba, 0xdf, 0xdf,
	0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
	0xdf, 0xe3, 0xe9, 0xda, 0xc9, 0xcd, 0xd7, 0xf2,
	0xfa, 0xfb, 0xfa, 0xf1, 0xdc, 0xd5, 0xca, 0xaf,
	0xae, 0x95, 0x86, 0x85, 0x85, 0x7b, 0x7a, 0x7a,
	0x7a, 0x79, 0x75, 0x61, 0x60, 0x5e, 0x56, 0x54,
	0x58, 0x3d, 0x3e, 0x3c, 0x37, 0x39, 0x39, 0x36,
	0x39, 0x2f, 0x30, 0x30, 0x2c, 0x32, 0x35, 0x35,
	0x23, 0x1b, 0x1b, 0x1b, 0x1a, 0x1a, 0x4b, 0xa5,
	0xc3, 0xe1, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0d, 0xe5, 0xd0, 0xe9, 0xce, 0xb2, 0xce,
	0xd9, 0xee, 0xfe, 0xff, 0xfa, 0xdc, 0xd8, 0xb2,
	0xae, 0xa2, 0x86, 0x85, 0x7b, 0x7b, 0x7a, 0x7a,
	0x79, 0x79, 0x79, 0x76, 0x60, 0x5e, 0x5e, 0x5e,
	0x56, 0x54, 0x3d, 0x3d, 0x3c, 0x3c, 0x37, 0x37,
	0x36, 0x2e, 0x2f, 0x2f, 0x2f, 0x2b, 0x2b, 0x2c,
	0x19, 0x1c, 0x35, 0x23, 0x23, 0x1a, 0x1a, 0x23,
	0x4b, 0x4c, 0xba, 0xe1, 0xb9, 0x05, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x25, 0xe9, 0xd0, 0xe6, 0xb4,
	0xb0, 0xcc, 0xd8, 0xfa, 0xff, 0xff, 0xfa, 0xd8,
	0xd5, 0xa2, 0x90, 0x82, 0x85, 0x7b, 0x7a, 0x7a,
	0x79, 0x79, 0x79, 0x79, 0x79, 0x76, 0x60, 0x5e,
	0x5e, 0x58, 0x56, 0x54, 0x3d, 0x3d, 0x3c, 0x37,
	0x37, 0x36, 0x36, 0x2e, 0x2e, 0x2f, 0x2f, 0x2b,
	0x2b, 0x2b, 0x2b, 0x19, 0x19, 0x1c, 0x23, 0x23,
	0x23, 0x23, 0x4b, 0x4b, 0xa5, 0xdf, 0xbc, 0x0b,
	0x00, 0x00, 0x00, 0x00, 0x02, 0xb8, 0xe4, 0xd0,
	0xce, 0xa3, 0xad, 0xcc, 0xd8, 0xfa, 0xff, 0xfb,
	0xe7, 0xd5, 0xad, 0x92, 0x85, 0x85, 0x78, 0x7a,
	0x7a, 0x79, 0x79, 0x79, 0x79, 0x76, 0x76, 0x60,
	0x5e, 0x5e, 0x56, 0x56, 0x54, 0x54, 0x3d, 0x3d,
	0x3c, 0x37, 0x37, 0x36, 0x36, 0x2e, 0x2e, 0x2d,
	0x2d, 0x2a, 0x2a, 0x2b, 0x18, 0x18, 0x19, 0x15,
	0x1c, 0x1a, 0x1a, 0x23, 0x23, 0x4a, 0x51, 0xc5,
	0xe2, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x05, 0xbc,
	0xe3, 0xc4, 0xa3, 0x95, 0xb1, 0xb3, 0xd8, 0xee,
	0xfa, 0xef, 0xd5, 0xad, 0x94, 0x86, 0x78, 0x77,
	0x77, 0x7a, 0x76, 0x76, 0x79, 0x79, 0x76, 0x76,
	0x76, 0x60, 0x5e, 0x56, 0x56, 0x54, 0x54, 0x3d,
	0x3d, 0x3c, 0x3c, 0x37, 0x37, 0x36, 0x2e, 0x2e,
	0x2d, 0x2d, 0x2a, 0x2a, 0x29, 0x29, 0x17, 0x16,
	0x18, 0x14, 0x15, 0x15, 0x1c, 0x1b, 0x35, 0x35,
	0x49, 0xc3, 0xe1, 0x21, 0x00, 0x00, 0x00, 0x00,
	0x0b, 0xe1, 0xd0, 0xc4, 0x8b, 0x94, 0xad, 0xb3,
	0xcd, 0xd6, 0xd8, 0xcd, 0xb1, 0x94, 0x91, 0x7c,
	0x77, 0x77, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76,
	0x76, 0x76, 0x75, 0x5e, 0x56, 0x56, 0x56, 0x54,
	0x54, 0x3d, 0x3d, 0x3c, 0x3c, 0x37, 0x37, 0x36,
	0x2e, 0x2d, 0x2d, 0x2d, 0x2a, 0x2a, 0x29, 0x29,
	0x17, 0x16, 0x18, 0x14, 0x14, 0x14, 0x15, 0x15,
	0x1c, 0x19, 0x49, 0xc2, 0xf4, 0x25, 0x00, 0x00,
	0x00, 0x00, 0x0e, 0xe1, 0xc5, 0xbf, 0x8a, 0x90,
	0xa8, 0xad, 0xb2, 0xcc, 0xb2, 0xad, 0x95, 0x92,
	0x91, 0x78, 0x75, 0x75, 0x75, 0x75, 0x75, 0x76,
	0x76, 0x75, 0x76, 0x75, 0x75, 0x5e, 0x56, 0x56,
	0x54, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c, 0x37, 0x36,
	0x36, 0x36, 0x2d, 0x2d, 0x2d, 0x2d, 0x2a, 0x29,
	0x29, 0x17, 0x17, 0x16, 0x16, 0x17, 0x18, 0x14,
	0x14, 0x14, 0x14, 0x18, 0x44, 0xc2, 0xf5, 0xb7,
	0x02, 0x00, 0x00, 0x00, 0x1f, 0xf5, 0xc4, 0xa0,
	0x6f, 0x8f, 0x90, 0x95, 0xad, 0xad, 0x95, 0x94,
	0x92, 0x91, 0x91, 0x78, 0x75, 0x75, 0x75, 0x75,
	0x75, 0x76, 0x75, 0x75, 0x75, 0x75, 0x60, 0x56,
	0x56, 0x54, 0x54, 0x3d, 0x3d, 0x3c, 0x3c, 0x37,
	0x37, 0x36, 0x36, 0x36, 0x2e, 0x2d, 0x2d, 0x2a,
	0x2a, 0x29, 0x29, 0x17, 0x29, 0x2a, 0x2d, 0x2d,
	0x13, 0x13, 0x14, 0x13, 0x14, 0x18, 0x44, 0xc2,
	0xfa, 0xb8, 0x02, 0x00, 0x00, 0x00, 0x20, 0xf5,
	0xc4, 0x9d, 0x6d, 0x80, 0x8f, 0x88, 0x90, 0x90,
	0x92, 0x91, 0x86, 0x83, 0x83, 0x7c, 0x75, 0x75,
	0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75,
	0x5e, 0x54, 0x54, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c,
	0x3c, 0x37, 0x37, 0x36, 0x36, 0x2d, 0x2e, 0x2d,
	0x2d, 0x2a, 0x2a, 0x29, 0x29, 0x2a, 0x36, 0x37,
	0x36, 0x17, 0x13, 0x13, 0x13, 0x13, 0x13, 0x18,
	0x44, 0xd5, 0xf5, 0xbb, 0x02, 0x00, 0x00, 0x00,
	0x21, 0xf5, 0xc0, 0x50, 0x68, 0x6b, 0x80, 0x80,
	0x80, 0x83, 0x80, 0x82, 0x82, 0x82, 0x83, 0x7e,
	0x60, 0x75, 0x60, 0x75, 0x75, 0x75, 0x75, 0x75,
	0x75, 0x60, 0x5e, 0x54, 0x3d, 0x3d, 0x3d, 0x3d,
	0x3c, 0x3c, 0x37, 0x37, 0x36, 0x36, 0x2e, 0x2d,
	0x2d, 0x2d, 0x2a, 0x2a, 0x2a, 0x2d, 0x37, 0x3c,
	0x37, 0x37, 0x2a, 0x13, 0x13, 0x13, 0x16, 0x18,
	0x17, 0x29, 0x44, 0xd8, 0xf4, 0xbb, 0x02, 0x00,
	0x00, 0x00, 0x21, 0xf5, 0xc4, 0x49, 0x68, 0x6a,
	0x7c, 0x7d, 0x7e, 0x7e, 0x7e, 0x7e, 0x82, 0x82,
	0x82, 0x82, 0x75, 0x60, 0x60, 0x60, 0x60, 0x60,
	0x60, 0x60, 0x60, 0x60, 0x56, 0x3d, 0x3d, 0x3d,
	0x3c, 0x3c, 0x37, 0x37, 0x37, 0x36, 0x36, 0x2e,
	0x2e, 0x2d, 0x2d, 0x2d, 0x2d, 0x2e, 0x3c, 0x3c,
	0x3c, 0x3c, 0x37, 0x2e, 0x16, 0x13, 0x16, 0x16,
	0x17, 0x17, 0x29, 0x2a, 0x46, 0xd8, 0xfa, 0xbb,
	0x02, 0x00, 0x00, 0x00, 0x1f, 0xf5, 0xc4, 0x50,
	0x59, 0x6a, 0x6a, 0x7c, 0x7c, 0x7e, 0x7d, 0x7e,
	0x7e, 0x7e, 0x82, 0x82, 0x65, 0x5e, 0x60, 0x60,
	0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x56, 0x3d,
	0x3c, 0x3c, 0x3c, 0x37, 0x37, 0x37, 0x36, 0x36,
	0x2e, 0x2e, 0x2e, 0x2d, 0x2d, 0x36, 0x3c, 0x3d,
	0x3c, 0x3c, 0x3c, 0x37, 0x37, 0x29, 0x13, 0x13,
	0x16, 0x17, 0x17, 0x29, 0x2a, 0x2f, 0x8b, 0xdc,
	0xf9, 0xb8, 0x02, 0x00, 0x00, 0x00, 0x0d, 0xf5,
	0xc4, 0x47, 0x40, 0x63, 0x64, 0x64, 0x64, 0x7c,
	0x7c, 0x7c, 0x7e, 0x85, 0x7e, 0x7e, 0x7c, 0x60,
	0x60, 0x5e, 0x60, 0x5e, 0x60, 0x5e, 0x60, 0x5e,
	0x54, 0x3c, 0x3c, 0x3c, 0x37, 0x37, 0x37, 0x36,
	0x36, 0x36, 0x36, 0x2d, 0x2d, 0x36, 0x3d, 0x3d,
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x37, 0x36, 0x16,
	0x13, 0x13, 0x16, 0x17, 0x29, 0x2a, 0x2a, 0x2e,
	0xad, 0xdc, 0xf1, 0xb8, 0x02, 0x00, 0x00, 0x00,
	0x0c, 0xe5, 0xe0, 0x4e, 0x3f, 0x5b, 0x65, 0x6a,
	0x64, 0x7c, 0x7c, 0x7c, 0x7d, 0x7c, 0x7e, 0x7e,
	0x7e, 0x61, 0x5e, 0x5e, 0x5e, 0x60, 0x5e, 0x5e,
	0x5e, 0x5e, 0x3d, 0x3c, 0x37, 0x37, 0x37, 0x36,
	0x36, 0x36, 0x36, 0x2e, 0x2d, 0x36, 0x3c, 0x3d,
	0x3d, 0x3d, 0x3d, 0x3c, 0x3c, 0x37, 0x37, 0x37,
	0x2a, 0x13, 0x13, 0x16, 0x17, 0x29, 0x29, 0x2a,
	0x2d, 0x43, 0xd5, 0xdc, 0xf4, 0xb7, 0x00, 0x00,
	0x00, 0x00, 0x06, 0xdf, 0xe4, 0x50, 0x38, 0x40,
	0x62, 0x65, 0x64, 0x64, 0x7c, 0x7c, 0x7c, 0x7e,
	0x7d, 0x7e, 0x7e, 0x64, 0x5e, 0x5e, 0x5e, 0x5e,
	0x5e, 0x5e, 0x5e, 0x5e, 0x3d, 0x37, 0x37, 0x37,
	0x36, 0x36, 0x36, 0x2e, 0x2e, 0x2d, 0x36, 0x3d,
	0x3d, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c, 0x3c, 0x37,
	0x37, 0x36, 0x17, 0x13, 0x16, 0x16, 0x17, 0x29,
	0x2a, 0x2d, 0x36, 0x95, 0xdb, 0xdc, 0xf4, 0x25,
	0x00, 0x00, 0x00, 0x00, 0x05, 0xbc, 0xf9, 0x4f,
	0x2f, 0x3f, 0x5c, 0x64, 0x64, 0x64, 0x64, 0x64,
	0x7c, 0x7c, 0x7d, 0x7d, 0x7d, 0x7d, 0x5f, 0x5e,
	0x56, 0x56, 0x5e, 0x5e, 0x5e, 0x56, 0x3c, 0x36,
	0x36, 0x36, 0x36, 0x36, 0x2e, 0x2e, 0x2d, 0x36,
	0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c, 0x3c,
	0x3c, 0x37, 0x37, 0x2d, 0x16, 0x13, 0x16, 0x17,
	0x29, 0x29, 0x2d, 0x2d, 0x44, 0xb5, 0xdd, 0xef,
	0xe1, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb9,
	0xfc, 0x52, 0x31, 0x3f, 0x3f, 0x5c, 0x63, 0x65,
	0x64, 0x64, 0x7c, 0x7c, 0x7c, 0x7e, 0x7d, 0x7d,
	0x64, 0x56, 0x5e, 0x56, 0x56, 0x56, 0x56, 0x56,
	0x3c, 0x36, 0x36, 0x2e, 0x2e, 0x2e, 0x2e, 0x2d,
	0x36, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c,
	0x3c, 0x37, 0x37, 0x37, 0x37, 0x2a, 0x13, 0x13,
	0x16, 0x17, 0x29, 0x2a, 0x2d, 0x39, 0xad, 0xb6,
	0xdd, 0xf3, 0xe2, 0x0e, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x26, 0xfc, 0xc4, 0x30, 0x2f, 0x3f, 0x3f,
	0x59, 0x62, 0x64, 0x64, 0x6a, 0x64, 0x7c, 0x7c,
	0x7c, 0x7d, 0x7d, 0x65, 0x56, 0x56, 0x56, 0x56,
	0x56, 0x56, 0x37, 0x2e, 0x2e, 0x2e, 0x2e, 0x2d,
	0x2d, 0x36, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3c,
	0x3c, 0x3c, 0x3c, 0x37, 0x37, 0x37, 0x36, 0x29,
	0x13, 0x16, 0x17, 0x29, 0x2a, 0x2a, 0x2e, 0x96,
	0xb6, 0xdb, 0xdd, 0xf3, 0xbd, 0x06, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0e, 0xe1, 0xe5, 0x32, 0x2d,
	0x3f, 0x3f, 0x3f, 0x5a, 0x63, 0x65, 0x64, 0x64,
	0x6a, 0x64, 0x7c, 0x7c, 0x7d, 0x7c, 0x57, 0x56,
	0x54, 0x54, 0x56, 0x54, 0x37, 0x2e, 0x2e, 0x2d,
	0x2d, 0x2d, 0x36, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
	0x3c, 0x3c, 0x3c, 0x37, 0x3c, 0x37, 0x37, 0x36,
	0x36, 0x17, 0x16, 0x17, 0x29, 0x29, 0x2d, 0x2d,
	0x47, 0xb5, 0xdb, 0xdd, 0xf3, 0xf4, 0xb7, 0x02,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xbc, 0xfd,
	0x4f, 0x2a, 0x2f, 0x38, 0x3f, 0x59, 0x65, 0x63,
	0x65, 0x64, 0x64, 0x64, 0x6a, 0x7c, 0x6b, 0x7c,
	0x6a, 0x57, 0x54, 0x54, 0x54, 0x54, 0x37, 0x2d,
	0x2d, 0x2d, 0x2d, 0x2d, 0x3c, 0x3d, 0x3d, 0x3d,
	0x3d, 0x3c, 0x3c, 0x3c, 0x37, 0x37, 0x37, 0x37,
	0x36, 0x36, 0x36, 0x17, 0x16, 0x17, 0x29, 0x2a,
	0x2d, 0x43, 0xb1, 0xb6, 0xdb, 0xdd, 0xf3, 0xe5,
	0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x25, 0xfe, 0xc3, 0x2b, 0x2d, 0x38, 0x38, 0x55,
	0x62, 0x62, 0x63, 0x63, 0x64, 0x64, 0x64, 0x6a,
	0x7c, 0x6b, 0x7d, 0x64, 0x57, 0x54, 0x3d, 0x3d,
	0x37, 0x2d, 0x2d, 0x2a, 0x2a, 0x37, 0x3d, 0x3d,
	0x3c, 0x3d, 0x3c, 0x3c, 0x3c, 0x37, 0x3c, 0x37,
	0x37, 0x37, 0x36, 0x36, 0x36, 0x29, 0x17, 0x29,
	0x2a, 0x2d, 0x5c, 0x95, 0xb1, 0xb5, 0xdb, 0xf3,
	0xf3, 0xbc, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0e, 0xe1, 0xf9, 0x34, 0x29, 0x36,
	0x3f, 0x55, 0x5a, 0x62, 0x62, 0x63, 0x63, 0x64,
	0x64, 0x6a, 0x6a, 0x6a, 0x6a, 0x6b, 0x6a, 0x57,
	0x3d, 0x3d, 0x37, 0x2a, 0x2a, 0x2a, 0x2d, 0x3c,
	0x3d, 0x3d, 0x3c, 0x3c, 0x3c, 0x3c, 0x37, 0x37,
	0x37, 0x37, 0x37, 0x36, 0x36, 0x36, 0x36, 0x17,
	0x29, 0x29, 0x2a, 0x39, 0x89, 0x96, 0xad, 0xb1,
	0xd8, 0xf3, 0xf4, 0xb7, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x02, 0xb8, 0xfe, 0xbe,
	0x18, 0x2a, 0x2f, 0x3e, 0x57, 0x5a, 0x5f, 0x62,
	0x62, 0x63, 0x63, 0x63, 0x6a, 0x6a, 0x6a, 0x6b,
	0x69, 0x6b, 0x59, 0x3d, 0x37, 0x2a, 0x2a, 0x29,
	0x2e, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x37,
	0x37, 0x37, 0x37, 0x36, 0x36, 0x36, 0x37, 0x37,
	0x36, 0x29, 0x29, 0x2d, 0x3a, 0x71, 0x70, 0x93,
	0x95, 0xb2, 0xd9, 0xef, 0xe2, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
	0xf5, 0xf5, 0x32, 0x18, 0x2d, 0x3e, 0x57, 0x57,
	0x5a, 0x62, 0x5f, 0x62, 0x63, 0x63, 0x63, 0x68,
	0x6a, 0x6a, 0x6a, 0x6b, 0x69, 0x63, 0x38, 0x29,
	0x29, 0x29, 0x37, 0x3c, 0x3c, 0x3c, 0x3c, 0x37,
	0x37, 0x37, 0x37, 0x36, 0x36, 0x36, 0x36, 0x37,
	0x37, 0x3c, 0x37, 0x29, 0x2f, 0x42, 0x71, 0x73,
	0x70, 0x70, 0x8b, 0xce, 0xd9, 0xed, 0xb8, 0x05,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x05, 0xbb, 0xfc, 0xbe, 0x18, 0x29, 0x36,
	0x57, 0x57, 0x57, 0x5a, 0x5a, 0x5a, 0x62, 0x63,
	0x63, 0x63, 0x63, 0x68, 0x6a, 0x6a, 0x6a, 0x69,
	0x68, 0x3a, 0x2a, 0x2a, 0x37, 0x3c, 0x3c, 0x37,
	0x37, 0x37, 0x37, 0x37, 0x36, 0x37, 0x36, 0x36,
	0x37, 0x37, 0x3c, 0x3c, 0x3e, 0x42, 0x71, 0x8a,
	0x8a, 0x89, 0x70, 0x70, 0xa3, 0xda, 0xda, 0xde,
	0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xe1, 0xf9, 0x34,
	0x16, 0x2a, 0x55, 0x55, 0x57, 0x57, 0x5a, 0x5a,
	0x5a, 0x5a, 0x63, 0x63, 0x63, 0x68, 0x68, 0x68,
	0x68, 0x69, 0x69, 0x67, 0x42, 0x42, 0x40, 0x3c,
	0x37, 0x37, 0x37, 0x37, 0x36, 0x36, 0x36, 0x36,
	0x36, 0x37, 0x37, 0x3e, 0x59, 0x69, 0x6f, 0x89,
	0x89, 0x89, 0x8a, 0x70, 0x70, 0x8b, 0xc9, 0xd2,
	0xda, 0xb9, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xb9,
	0xfe, 0xc4, 0x18, 0x17, 0x36, 0x55, 0x55, 0x55,
	0x55, 0x57, 0x5a, 0x5a, 0x63, 0x63, 0x5b, 0x63,
	0x68, 0x68, 0x68, 0x68, 0x68, 0x42, 0x42, 0x67,
	0x6d, 0x67, 0x67, 0x5c, 0x40, 0x3e, 0x38, 0x38,
	0x3c, 0x3f, 0x40, 0x67, 0x69, 0x6f, 0x8f, 0x8e,
	0x8f, 0x88, 0x88, 0x88, 0x88, 0x89, 0x89, 0xb0,
	0xd1, 0xd4, 0xc6, 0x1f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0c, 0xbc, 0xf5, 0x4f, 0x17, 0x29, 0x3c,
	0x55, 0x55, 0x55, 0x57, 0x59, 0x59, 0x5a, 0x5a,
	0x5b, 0x5b, 0x63, 0x5b, 0x68, 0x68, 0x68, 0x67,
	0x42, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6d, 0x6f,
	0x6f, 0x6f, 0x6f, 0x6f, 0x8f, 0x8f, 0x8f, 0x8e,
	0x8e, 0x8e, 0x8e, 0x88, 0x88, 0x88, 0x88, 0x89,
	0xa3, 0xcd, 0xd2, 0xc5, 0x25, 0x02, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x21, 0xe1, 0xe3, 0x33,
	0x29, 0x2a, 0x3e, 0x54, 0x55, 0x55, 0x55, 0x55,
	0x59, 0x5a, 0x5c, 0x5a, 0x5b, 0x5b, 0x68, 0x67,
	0x68, 0x67, 0x42, 0x67, 0x69, 0x69, 0x6d, 0x6d,
	0x6d, 0x6f, 0x6f, 0x81, 0x6f, 0x8d, 0x8f, 0x8f,
	0x8f, 0x8e, 0x8e, 0x8e, 0x8e, 0x8f, 0x8f, 0x88,
	0x90, 0xa2, 0xcd, 0xd2, 0xd4, 0xb8, 0x0b, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x27,
	0xf5, 0xc0, 0x31, 0x29, 0x2d, 0x3e, 0x3d, 0x54,
	0x55, 0x55, 0x59, 0x59, 0x59, 0x59, 0x5a, 0x5b,
	0x67, 0x5b, 0x67, 0x67, 0x42, 0x67, 0x69, 0x69,
	0x69, 0x6d, 0x6d, 0x6e, 0x80, 0x6f, 0x81, 0x8f,
	0x81, 0x81, 0x8d, 0x91, 0x8e, 0x91, 0x8e, 0x8e,
	0x88, 0x88, 0x95, 0xca, 0xce, 0xd2, 0xbd, 0x0d,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x06, 0xb9, 0xf5, 0x9e, 0x2f, 0x2a, 0x2d,
	0x3e, 0x55, 0x3e, 0x55, 0x55, 0x55, 0x59, 0x5c,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x67, 0x42, 0x67,
	0x69, 0x69, 0x69, 0x69, 0x6d, 0x6e, 0x6e, 0x80,
	0x81, 0x81, 0x81, 0x8f, 0x8d, 0x8e, 0x91, 0x8e,
	0x8e, 0x8e, 0x8e, 0x95, 0xca, 0xce, 0xcd, 0xc3,
	0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0b, 0xb8, 0xe5, 0x9d,
	0x2f, 0x2d, 0x2e, 0x3e, 0x55, 0x55, 0x55, 0x55,
	0x59, 0x59, 0x59, 0x5a, 0x5b, 0x5b, 0x5b, 0x5b,
	0x40, 0x67, 0x68, 0x69, 0x69, 0x6b, 0x6e, 0x6e,
	0x6e, 0x80, 0x81, 0x81, 0x81, 0x83, 0x8d, 0x8d,
	0x8d, 0x8d, 0x91, 0x8e, 0x95, 0xb2, 0xcd, 0xcd,
	0xc3, 0x26, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b,
	0xb8, 0xe3, 0x9d, 0x39, 0x2e, 0x36, 0x37, 0x54,
	0x55, 0x57, 0x57, 0x59, 0x5a, 0x5a, 0x5a, 0x5a,
	0x63, 0x5b, 0x42, 0x67, 0x68, 0x6a, 0x6a, 0x6b,
	0x6b, 0x80, 0x6b, 0x80, 0x80, 0x81, 0x83, 0x83,
	0x83, 0x83, 0x8d, 0x8d, 0x8e, 0xad, 0xca, 0xce,
	0xce, 0xc3, 0x21, 0x02, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0b, 0xb7, 0xe3, 0x9d, 0x3a, 0x36,
	0x36, 0x38, 0x3d, 0x57, 0x57, 0x57, 0x57, 0x5f,
	0x5a, 0x62, 0x63, 0x63, 0x5c, 0x5c, 0x6a, 0x6a,
	0x6a, 0x6b, 0x7d, 0x7d, 0x7d, 0x80, 0x80, 0x82,
	0x82, 0x82, 0x83, 0x83, 0x91, 0x94, 0xa8, 0xb2,
	0xca, 0xce, 0xc2, 0x21, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x25, 0xc5,
	0xbf, 0x43, 0x3c, 0x3c, 0x3c, 0x3d, 0x54, 0x57,
	0x5f, 0x62, 0x5f, 0x62, 0x62, 0x63, 0x5b, 0x5c,
	0x68, 0x6a, 0x6a, 0x7c, 0x6b, 0x7d, 0x7d, 0x7d,
	0x80, 0x82, 0x82, 0x83, 0x82, 0x91, 0x94, 0xaa,
	0xb1, 0xca, 0xce, 0xba, 0x1f, 0x02, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x02, 0x22, 0xbd, 0xc0, 0x97, 0x5d, 0x3e, 0x3e,
	0x3d, 0x3d, 0x57, 0x57, 0x61, 0x62, 0x65, 0x63,
	0x5b, 0x5c, 0x63, 0x64, 0x64, 0x64, 0x7c, 0x7c,
	0x7c, 0x7e, 0x7e, 0x82, 0x82, 0x83, 0x94, 0xa9,
	0xaa, 0xb1, 0xb2, 0xc2, 0x4d, 0x0c, 0x02, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x27, 0xc3, 0xa0,
	0x73, 0x5d, 0x58, 0x55, 0x3d, 0x54, 0x57, 0x57,
	0x5f, 0x5f, 0x59, 0x59, 0x63, 0x64, 0x7c, 0x78,
	0x7c, 0x85, 0x7c, 0x7c, 0x7f, 0x84, 0x94, 0xa7,
	0xaa, 0xaa, 0xb1, 0xb3, 0xa5, 0x21, 0x05, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
	0x1f, 0x4d, 0xbe, 0x9d, 0x74, 0x72, 0x66, 0x5d,
	0x5d, 0x58, 0x57, 0x55, 0x55, 0x55, 0x5c, 0x62,
	0x65, 0x64, 0x7c, 0x7d, 0x80, 0x8e, 0x94, 0xa9,
	0xa9, 0xaa, 0xaa, 0xaa, 0xa6, 0x28, 0x0e, 0x02,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x05, 0x1f, 0x4d, 0xa5, 0x9a,
	0x9b, 0x74, 0x74, 0x74, 0x72, 0x72, 0x6c, 0x6c,
	0x6c, 0x74, 0x89, 0x90, 0x94, 0xa7, 0xa7, 0xa9,
	0xa9, 0xa9, 0xaa, 0xab, 0xa6, 0x28, 0x0f, 0x02,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
	0x0c, 0x21, 0x4d, 0x53, 0x9a, 0x9a, 0x9b, 0x9b,
	0x99, 0x99, 0x99, 0xa1, 0xa2, 0xa2, 0xa8, 0xa7,
	0xab, 0xab, 0xac, 0xac, 0x4c, 0x1e, 0x0a, 0x02,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x02, 0x02, 0x0a, 0x0d, 0x22,
	0x23, 0x4b, 0x4e, 0x50, 0x50, 0x4f, 0x50, 0x50,
	0x4c, 0x4c, 0x4a, 0x1e, 0x0f, 0x0a, 0x02, 0x00,
	0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x02, 0x02, 0x05, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

unsigned int logo_img_size = sizeof(logo_img);
