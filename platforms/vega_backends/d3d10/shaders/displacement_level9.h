#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /nologo /Zpc /Tps_4_0_level_9_1 /Dop_main=displacementLevel9
//    /EdisplacementLevel9 /Fhdisplacement_level9.h displacement.psh
//
//
// Buffer Definitions: 
//
// cbuffer constants
// {
//
//   float4 xselector;                  // Offset:    0 Size:    16
//   float4 yselector;                  // Offset:   16 Size:    16
//   float2 srcScale;                   // Offset:   32 Size:     8
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// srcSampler                        sampler      NA          NA    0        1
// displaceSampler                   sampler      NA          NA    1        1
// srcTex                            texture  float4          2d    0        1
// displaceTex                       texture  float4          2d    1        1
// constants                         cbuffer      NA          NA    0        1
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
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             0         3  ( FLT, FLT, FLT, FLT)
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
// s1             s1              t1               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    def c3, -0.5, 1, 0, 0
    dcl t1
    dcl_2d s0
    dcl_2d s1
    mov r0.xy, t1.wzyx
    texld r0, r0, s1
    dp4 r1.x, c0, r0
    dp4 r1.y, c1, r0
    add r0.xy, r1, c3.x
    mad r0.xy, r0, c2, t1
    texld r1, r0, s0
    add r0.z, -r0.y, c3.y
    cmp r1, r0.z, r1, c3.z
    cmp r1, r0.y, r1, c3.z
    add r0.y, -r0.x, c3.y
    cmp r1, r0.y, r1, c3.z
    cmp r0, r0.x, r1, c3.z
    mov oC0, r0

// approximately 14 instruction slots used (2 texture, 12 arithmetic)
ps_4_0
dcl_constantbuffer cb0[3], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_input_ps linear v2.xy
dcl_input_ps linear v2.zw
dcl_output o0.xyzw
dcl_temps 3
sample r0.xyzw, v2.zwzz, t1.xyzw, s1
dp4 r1.x, cb0[0].xyzw, r0.xyzw
dp4 r1.y, cb0[1].xyzw, r0.xyzw
add r0.xy, r1.xyxx, l(-0.500000, -0.500000, 0.000000, 0.000000)
mad r0.xy, r0.xyxx, cb0[2].xyxx, v2.xyxx
ge r0.zw, r0.xxxy, l(0.000000, 0.000000, 0.000000, 0.000000)
and r0.zw, r0.zzzw, l(0, 0, 0x3f800000, 0x3f800000)
ge r1.xy, l(1.000000, 1.000000, 0.000000, 0.000000), r0.xyxx
sample r2.xyzw, r0.xyxx, t0.xyzw, s0
and r0.xy, r1.xyxx, l(0x3f800000, 0x3f800000, 0, 0)
mul r0.x, r0.x, r0.z
mul r0.x, r0.w, r0.x
mul r0.x, r0.y, r0.x
mul o0.xyzw, r0.xxxx, r2.xyzw
ret 
// Approximately 15 instruction slots used
#endif

const BYTE g_displacementLevel9[] =
{
     68,  88,  66,  67,  31,  73, 
    106,  79,  28, 127,  75,  11, 
    229, 134, 187,  77, 194, 241, 
     83, 105,   1,   0,   0,   0, 
     36,   7,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
    168,   1,   0,   0,  24,   4, 
      0,   0, 148,   4,   0,   0, 
    100,   6,   0,   0, 240,   6, 
      0,   0,  65, 111, 110,  57, 
    104,   1,   0,   0, 104,   1, 
      0,   0,   0,   2, 255, 255, 
     48,   1,   0,   0,  56,   0, 
      0,   0,   1,   0,  44,   0, 
      0,   0,  56,   0,   0,   0, 
     56,   0,   2,   0,  36,   0, 
      0,   0,  56,   0,   0,   0, 
      0,   0,   1,   1,   1,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   2, 255, 255,  81,   0, 
      0,   5,   3,   0,  15, 160, 
      0,   0,   0, 191,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      1,   0,  15, 176,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      1,   8,  15, 160,   1,   0, 
      0,   2,   0,   0,   3, 128, 
      1,   0,  27, 176,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   1,   8, 
    228, 160,   9,   0,   0,   3, 
      1,   0,   1, 128,   0,   0, 
    228, 160,   0,   0, 228, 128, 
      9,   0,   0,   3,   1,   0, 
      2, 128,   1,   0, 228, 160, 
      0,   0, 228, 128,   2,   0, 
      0,   3,   0,   0,   3, 128, 
      1,   0, 228, 128,   3,   0, 
      0, 160,   4,   0,   0,   4, 
      0,   0,   3, 128,   0,   0, 
    228, 128,   2,   0, 228, 160, 
      1,   0, 228, 176,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      0,   0, 228, 128,   0,   8, 
    228, 160,   2,   0,   0,   3, 
      0,   0,   4, 128,   0,   0, 
     85, 129,   3,   0,  85, 160, 
     88,   0,   0,   4,   1,   0, 
     15, 128,   0,   0, 170, 128, 
      1,   0, 228, 128,   3,   0, 
    170, 160,  88,   0,   0,   4, 
      1,   0,  15, 128,   0,   0, 
     85, 128,   1,   0, 228, 128, 
      3,   0, 170, 160,   2,   0, 
      0,   3,   0,   0,   2, 128, 
      0,   0,   0, 129,   3,   0, 
     85, 160,  88,   0,   0,   4, 
      1,   0,  15, 128,   0,   0, 
     85, 128,   1,   0, 228, 128, 
      3,   0, 170, 160,  88,   0, 
      0,   4,   0,   0,  15, 128, 
      0,   0,   0, 128,   1,   0, 
    228, 128,   3,   0, 170, 160, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0,  83,  72, 
     68,  82, 104,   2,   0,   0, 
     64,   0,   0,   0, 154,   0, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
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
      0,   0,   0,   0, 230,  26, 
     16,   0,   2,   0,   0,   0, 
     70, 126,  16,   0,   1,   0, 
      0,   0,   0,  96,  16,   0, 
      1,   0,   0,   0,  17,   0, 
      0,   8,  18,   0,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     17,   0,   0,   8,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0, 191, 
      0,   0,   0, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  10,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,  70, 128,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  70,  16,  16,   0, 
      2,   0,   0,   0,  29,   0, 
      0,  10, 194,   0,  16,   0, 
      0,   0,   0,   0,   6,   4, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,  10, 
    194,   0,  16,   0,   0,   0, 
      0,   0, 166,  14,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
     29,   0,   0,  10,  50,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,  10,  50,   0,  16,   0, 
      0,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    242,  32,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     15,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   9,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  82,  68,  69,  70, 
    200,   1,   0,   0,   1,   0, 
      0,   0, 244,   0,   0,   0, 
      5,   0,   0,   0,  28,   0, 
      0,   0,   0,   4, 255, 255, 
     16,   1,   0,   0, 148,   1, 
      0,   0, 188,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 199,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    215,   0,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0, 222,   0,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     12,   0,   0,   0, 234,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
    115, 114,  99,  83,  97, 109, 
    112, 108, 101, 114,   0, 100, 
    105, 115, 112, 108,  97,  99, 
    101,  83,  97, 109, 112, 108, 
    101, 114,   0, 115, 114,  99, 
     84, 101, 120,   0, 100, 105, 
    115, 112, 108,  97,  99, 101, 
     84, 101, 120,   0,  99, 111, 
    110, 115, 116,  97, 110, 116, 
    115,   0, 234,   0,   0,   0, 
      3,   0,   0,   0,  12,   1, 
      0,   0,  48,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  84,   1,   0,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     96,   1,   0,   0,   0,   0, 
      0,   0, 112,   1,   0,   0, 
     16,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
     96,   1,   0,   0,   0,   0, 
      0,   0, 122,   1,   0,   0, 
     32,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
    132,   1,   0,   0,   0,   0, 
      0,   0, 120, 115, 101, 108, 
    101,  99, 116, 111, 114,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    121, 115, 101, 108, 101,  99, 
    116, 111, 114,   0, 115, 114, 
     99,  83,  99,  97, 108, 101, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  57, 
     46,  50,  57,  46,  57,  53, 
     50,  46,  51,  49,  49,  49, 
      0, 171, 171, 171,  73,  83, 
     71,  78, 132,   0,   0,   0, 
      4,   0,   0,   0,   8,   0, 
      0,   0, 104,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 116,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0, 122,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,   3, 
      0,   0, 122,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,  12,  12, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  67,  79,  76,  79, 
     82,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171
};