#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /D SWRAP=1 /D TWRAP=3 /nologo /Zpc /Tps_4_0_level_9_1
//    /Dop_main=Vector2d /EVector2d /FhVector2d_REPEAT_MIRROR_level9.h /Vn
//    g_ps20_Vector2d_REPEAT_MIRROR vector2d.psh
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// linearSampler1                    sampler      NA          NA    0        1
// tex1                              texture  float4          2d    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// COLOR                    0   xyzw        1     NONE  float   xyzw
// TEXCOORD                 0   xy          2     NONE  float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    def c0, 2, -2, 0.5, -0.5
    def c1, -1, 1, 0, 0
    dcl t0
    dcl t1.xy
    dcl_2d s0
    cmp r0.w, t1.y, c0.z, c0.w
    mul r0.x, r0.w, t1.y
    frc r0.x, r0.x
    cmp r0.y, t1.y, c0.x, c0.y
    mad r0.x, r0.y, r0.x, c1.x
    frc r0.y, t1.y
    add r0.z, -r0.y, c1.y
    cmp r0.y, r0.x, r0.z, r0.y
    frc r0.x, t1.x
    texld r0, r0, s0
    mul r0, r0, t0
    mov oC0, r0

// approximately 12 instruction slots used (1 texture, 11 arithmetic)
ps_4_0
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v2.xy
dcl_output o0.xyzw
dcl_temps 2
add r0.x, v2.y, v2.y
ge r0.x, r0.x, -r0.x
movc r0.xy, r0.xxxx, l(2.000000,0.500000,0,0), l(-2.000000,-0.500000,0,0)
mul r0.y, r0.y, v2.y
frc r0.y, r0.y
mul r0.x, r0.y, r0.x
lt r0.x, r0.x, l(1.000000)
frc r1.xy, v2.xyxx
add r0.y, -r1.y, l(1.000000)
movc r1.z, r0.x, r1.y, r0.y
sample r0.xyzw, r1.xzxx, t0.xyzw, s0
mul o0.xyzw, r0.xyzw, v1.xyzw
ret 
// Approximately 13 instruction slots used
#endif

const BYTE g_ps20_Vector2d_REPEAT_MIRROR[] =
{
     68,  88,  66,  67, 224, 179, 
    164, 103, 205, 232, 208, 130, 
    180,  90, 219,  63,   2, 249, 
    149, 181,   1,   0,   0,   0, 
     40,   5,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
    132,   1,   0,   0,  88,   3, 
      0,   0, 212,   3,   0,   0, 
    128,   4,   0,   0, 244,   4, 
      0,   0,  65, 111, 110,  57, 
     68,   1,   0,   0,  68,   1, 
      0,   0,   0,   2, 255, 255, 
     28,   1,   0,   0,  40,   0, 
      0,   0,   0,   0,  40,   0, 
      0,   0,  40,   0,   0,   0, 
     40,   0,   1,   0,  36,   0, 
      0,   0,  40,   0,   0,   0, 
      0,   0,   0,   2, 255, 255, 
     81,   0,   0,   5,   0,   0, 
     15, 160,   0,   0,   0,  64, 
      0,   0,   0, 192,   0,   0, 
      0,  63,   0,   0,   0, 191, 
     81,   0,   0,   5,   1,   0, 
     15, 160,   0,   0, 128, 191, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,  15, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   1,   0,   3, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     88,   0,   0,   4,   0,   0, 
      8, 128,   1,   0,  85, 176, 
      0,   0, 170, 160,   0,   0, 
    255, 160,   5,   0,   0,   3, 
      0,   0,   1, 128,   0,   0, 
    255, 128,   1,   0,  85, 176, 
     19,   0,   0,   2,   0,   0, 
      1, 128,   0,   0,   0, 128, 
     88,   0,   0,   4,   0,   0, 
      2, 128,   1,   0,  85, 176, 
      0,   0,   0, 160,   0,   0, 
     85, 160,   4,   0,   0,   4, 
      0,   0,   1, 128,   0,   0, 
     85, 128,   0,   0,   0, 128, 
      1,   0,   0, 160,  19,   0, 
      0,   2,   0,   0,   2, 128, 
      1,   0,  85, 176,   2,   0, 
      0,   3,   0,   0,   4, 128, 
      0,   0,  85, 129,   1,   0, 
     85, 160,  88,   0,   0,   4, 
      0,   0,   2, 128,   0,   0, 
      0, 128,   0,   0, 170, 128, 
      0,   0,  85, 128,  19,   0, 
      0,   2,   0,   0,   1, 128, 
      1,   0,   0, 176,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   0,   8, 
    228, 160,   5,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   0,   0, 228, 176, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0,  83,  72, 
     68,  82, 204,   1,   0,   0, 
     64,   0,   0,   0, 115,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   1,   0,   0,   0, 
     98,  16,   0,   3,  50,  16, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   2,   0, 
      0,   0,   0,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,  16,  16,   0, 
      2,   0,   0,   0,  26,  16, 
     16,   0,   2,   0,   0,   0, 
     29,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  55,   0,   0,  15, 
     50,   0,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0, 192,   0,   0,   0, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  26,  16, 
     16,   0,   2,   0,   0,   0, 
     26,   0,   0,   5,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     49,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  26,   0, 
      0,   5,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,  16, 
     16,   0,   2,   0,   0,   0, 
      0,   0,   0,   8,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  55,   0,   0,   9, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0, 134,   0,  16,   0, 
      1,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  30, 
     16,   0,   1,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     13,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   9,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  82,  68,  69,  70, 
    164,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  28,   0, 
      0,   0,   0,   4, 255, 255, 
     16,   1,   0,   0, 112,   0, 
      0,   0,  92,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 107,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
    108, 105, 110, 101,  97, 114, 
     83,  97, 109, 112, 108, 101, 
    114,  49,   0, 116, 101, 120, 
     49,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  50,  57,  46, 
     57,  53,  50,  46,  51,  49, 
     49,  49,   0, 171, 171, 171, 
     73,  83,  71,  78, 108,   0, 
      0,   0,   3,   0,   0,   0, 
      8,   0,   0,   0,  80,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  92,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,  15,   0,   0,  98,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   3,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171,  79,  83,  71,  78, 
     44,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     83,  86,  95,  84,  97, 114, 
    103, 101, 116,   0, 171, 171
};
