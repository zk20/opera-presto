#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /nologo /Zpc /Tps_4_0 /Dop_main=mergeDarken /EmergeDarken
//    /Fhmerge_darken.h merge_darken.psh
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// src1Sampler                       sampler      NA          NA    0        1
// src2Sampler                       sampler      NA          NA    1        1
// src1Tex                           texture  float4          2d    0        1
// src2Tex                           texture  float4          2d    1        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// COLOR                    0   xyzw        1     NONE  float       
// TEXCOORD                 0   xy          2     NONE  float   xy  
// TEXCOORD                 1     zw        2     NONE  float     zw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
ps_4_0
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_input_ps linear v2.xy
dcl_input_ps linear v2.zw
dcl_output o0.xyzw
dcl_temps 3
sample r0.xyzw, v2.xyxx, t0.xyzw, s0
add r0.w, -r0.w, l(1.000000)
sample r1.xyzw, v2.zwzz, t1.xyzw, s1
mad r2.xyz, r0.wwww, r1.xyzx, r0.xyzx
add r1.w, -r1.w, l(1.000000)
mad r0.xyz, r1.wwww, r0.xyzx, r1.xyzx
mad o0.w, -r0.w, r1.w, l(1.000000)
min o0.xyz, r0.xyzx, r2.xyzx
ret 
// Approximately 9 instruction slots used
#endif

const BYTE g_mergeDarken[] =
{
     68,  88,  66,  67, 233,  16, 
      2, 144, 204, 185,  55, 160, 
     19, 238,  21, 199, 254, 118, 
    117,  47,   1,   0,   0,   0, 
    252,   3,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     52,   1,   0,   0, 192,   1, 
      0,   0, 244,   1,   0,   0, 
    128,   3,   0,   0,  82,  68, 
     69,  70, 248,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    255, 255,  16,   1,   0,   0, 
    196,   0,   0,   0, 156,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    168,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 180,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     12,   0,   0,   0, 188,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
    115, 114,  99,  49,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    115, 114,  99,  50,  83,  97, 
    109, 112, 108, 101, 114,   0, 
    115, 114,  99,  49,  84, 101, 
    120,   0, 115, 114,  99,  50, 
     84, 101, 120,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  57,  46,  50, 
     57,  46,  57,  53,  50,  46, 
     51,  49,  49,  49,   0, 171, 
    171, 171,  73,  83,  71,  78, 
    132,   0,   0,   0,   4,   0, 
      0,   0,   8,   0,   0,   0, 
    104,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
    116,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,   0,   0,   0, 
    122,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   3,   0,   0, 
    122,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,  12,  12,   0,   0, 
     83,  86,  95,  80,  79,  83, 
     73,  84,  73,  79,  78,   0, 
     67,  79,  76,  79,  82,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171,  83,  72,  68,  82, 
    132,   1,   0,   0,  64,   0, 
      0,   0,  97,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   1,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      1,   0,   0,   0,  85,  85, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   2,   0, 
      0,   0,  98,  16,   0,   3, 
    194,  16,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      3,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  16, 
     16,   0,   2,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   8, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
    230,  26,  16,   0,   2,   0, 
      0,   0,  70, 126,  16,   0, 
      1,   0,   0,   0,   0,  96, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,   9, 114,   0, 
     16,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  50,   0,   0,   9, 
    114,   0,  16,   0,   0,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    130,  32,  16,   0,   0,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     51,   0,   0,   7, 114,  32, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0,   9,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
