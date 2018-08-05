#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /D SWRAP=2 /D TWRAP=1 /nologo /Zpc /Tps_4_0_level_9_1
//    /Dop_main=Vector2dTexGen /EVector2dTexGen
//    /FhVector2dTexGen_CLAMP_REPEAT_level9.h /Vn
//    g_ps20_Vector2dTexGen_CLAMP_REPEAT vector2dtexgen.psh
//
//
// Buffer Definitions: 
//
// cbuffer constants
// {
//
//   bool stencilComponentBased;        // Offset:    0 Size:     4
//   bool straightAlpha;                // Offset:   16 Size:     4
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// linearSampler1                    sampler      NA          NA    0        1
// linearSampler2                    sampler      NA          NA    1        1
// linearSampler3                    sampler      NA          NA    2        1
// tex1                              texture  float4          2d    0        1
// tex2                              texture  float4          2d    1        1
// tex3                              texture  float4          2d    2        1
// constants                         cbuffer      NA          NA    0        1
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
// TEXCOORD                 1     zw        2     NONE  float     zw
// TEXCOORD                 2   xy          3     NONE  float   xy  
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
// c0         cb0             0         2  (BOOL, FLT, FLT, FLT)
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
// s1             s1              t1               
// s2             s2              t2               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    def c2, -1, 0.0720999986, 0.715399981, 0.212500006
    dcl t0
    dcl t1
    dcl t2.xy
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2
    mov r0.w, c2.x
    add r0.x, r0.w, c0.x
    mul r0.x, r0.x, r0.x
    frc r1.y, t1.z
    mov r1.x, t1.w
    frc r2.y, t1.y
    mov r2.x, t1.x
    frc r3.y, t2.y
    mov r3.x, t2.x
    texld r1, r1, s1
    texld r2, r2, s0
    texld r3, r3, s2
    dp3 r0.y, r1, c2.wzyx
    cmp r0, -r0.x, r0.y, r1
    mul r0, r0, r2
    max r1.xyz, c1.x, r3.w
    mov r1.w, r3.w
    mul r0, r0, r1
    mul r0, r0, t0
    mov oC0, r0

// approximately 20 instruction slots used (3 texture, 17 arithmetic)
ps_4_0
dcl_constantbuffer cb0[2], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_sampler s2, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_resource_texture2d (float,float,float,float) t2
dcl_input_ps linear v1.xyzw
dcl_input_ps linear v2.xy
dcl_input_ps linear v2.zw
dcl_input_ps linear v3.xy
dcl_output o0.xyzw
dcl_temps 3
frc r0.yw, v2.wwwy
mov r0.xz, v2.zzxz
sample r1.xyzw, r0.xyxx, t1.xyzw, s1
sample r0.xyzw, r0.zwzz, t0.xyzw, s0
dp3 r2.x, r1.xyzx, l(0.212500, 0.715400, 0.072100, 0.000000)
movc r1.xyzw, cb0[0].xxxx, r2.xxxx, r1.xyzw
mul r0.xyzw, r0.xyzw, r1.xyzw
frc r1.y, v3.y
mov r1.x, v3.x
sample r1.xyzw, r1.xyxx, t2.xyzw, s2
movc r2.x, cb0[1].x, l(1.000000), l(0)
max r1.xyz, r1.wwww, r2.xxxx
mul r0.xyzw, r0.xyzw, r1.xyzw
mul o0.xyzw, r0.xyzw, v1.xyzw
ret 
// Approximately 15 instruction slots used
#endif

const BYTE g_ps20_Vector2dTexGen_CLAMP_REPEAT[] =
{
     68,  88,  66,  67, 145,  43, 
    126, 119, 144,  85,  13, 134, 
    163,  97, 141,  26, 100,  88, 
    245,  48,   1,   0,   0,   0, 
    180,   7,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
      4,   2,   0,   0, 100,   4, 
      0,   0, 224,   4,   0,   0, 
    220,   6,   0,   0, 128,   7, 
      0,   0,  65, 111, 110,  57, 
    196,   1,   0,   0, 196,   1, 
      0,   0,   0,   2, 255, 255, 
    136,   1,   0,   0,  60,   0, 
      0,   0,   1,   0,  48,   0, 
      0,   0,  60,   0,   0,   0, 
     60,   0,   3,   0,  36,   0, 
      0,   0,  60,   0,   0,   0, 
      0,   0,   1,   1,   1,   0, 
      2,   2,   2,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   0,   0,   0,   2, 
    255, 255,  81,   0,   0,   5, 
      2,   0,  15, 160,   0,   0, 
    128, 191,  42, 169, 147,  61, 
    116,  36,  55,  63, 154, 153, 
     89,  62,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   1,   0, 
     15, 176,  31,   0,   0,   2, 
      0,   0,   0, 128,   2,   0, 
      3, 176,  31,   0,   0,   2, 
      0,   0,   0, 144,   0,   8, 
     15, 160,  31,   0,   0,   2, 
      0,   0,   0, 144,   1,   8, 
     15, 160,  31,   0,   0,   2, 
      0,   0,   0, 144,   2,   8, 
     15, 160,   1,   0,   0,   2, 
      0,   0,   8, 128,   2,   0, 
      0, 160,   2,   0,   0,   3, 
      0,   0,   1, 128,   0,   0, 
    255, 128,   0,   0,   0, 160, 
      5,   0,   0,   3,   0,   0, 
      1, 128,   0,   0,   0, 128, 
      0,   0,   0, 128,  19,   0, 
      0,   2,   1,   0,   2, 128, 
      1,   0, 170, 176,   1,   0, 
      0,   2,   1,   0,   1, 128, 
      1,   0, 255, 176,  19,   0, 
      0,   2,   2,   0,   2, 128, 
      1,   0,  85, 176,   1,   0, 
      0,   2,   2,   0,   1, 128, 
      1,   0,   0, 176,  19,   0, 
      0,   2,   3,   0,   2, 128, 
      2,   0,  85, 176,   1,   0, 
      0,   2,   3,   0,   1, 128, 
      2,   0,   0, 176,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   1,   8, 
    228, 160,  66,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,   0,   8, 228, 160, 
     66,   0,   0,   3,   3,   0, 
     15, 128,   3,   0, 228, 128, 
      2,   8, 228, 160,   8,   0, 
      0,   3,   0,   0,   2, 128, 
      1,   0, 228, 128,   2,   0, 
     27, 160,  88,   0,   0,   4, 
      0,   0,  15, 128,   0,   0, 
      0, 129,   0,   0,  85, 128, 
      1,   0, 228, 128,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   2,   0, 
    228, 128,  11,   0,   0,   3, 
      1,   0,   7, 128,   1,   0, 
      0, 160,   3,   0, 255, 128, 
      1,   0,   0,   2,   1,   0, 
      8, 128,   3,   0, 255, 128, 
      5,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      1,   0, 228, 128,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   0,   0, 
    228, 176,   1,   0,   0,   2, 
      0,   8,  15, 128,   0,   0, 
    228, 128, 255, 255,   0,   0, 
     83,  72,  68,  82,  88,   2, 
      0,   0,  64,   0,   0,   0, 
    150,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   1,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   2,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   1,   0,   0,   0, 
     85,  85,   0,   0,  88,  24, 
      0,   4,   0, 112,  16,   0, 
      2,   0,   0,   0,  85,  85, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   1,   0, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   2,   0, 
      0,   0,  98,  16,   0,   3, 
    194,  16,  16,   0,   2,   0, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   3,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      3,   0,   0,   0,  26,   0, 
      0,   5, 162,   0,  16,   0, 
      0,   0,   0,   0, 246,  23, 
     16,   0,   2,   0,   0,   0, 
     54,   0,   0,   5,  82,   0, 
     16,   0,   0,   0,   0,   0, 
    166,  24,  16,   0,   2,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   1,   0,   0,   0, 
      0,  96,  16,   0,   1,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0, 230,  10,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  16,   0,   0,  10, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0, 154, 153,  89,  62, 
    116,  36,  55,  63,  42, 169, 
    147,  61,   0,   0,   0,   0, 
     55,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  56,   0, 
      0,   7, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  26,   0,   0,   5, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  26,  16,  16,   0, 
      3,   0,   0,   0,  54,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,  16, 
     16,   0,   3,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   0,  16,   0,   1,   0, 
      0,   0,  70, 126,  16,   0, 
      2,   0,   0,   0,   0,  96, 
     16,   0,   2,   0,   0,   0, 
     55,   0,   0,  10,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,   1,  64,   0,   0, 
      0,   0,   0,   0,  52,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   2,   0, 
      0,   0,  56,   0,   0,   7, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,   7, 242,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0,  15,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     82,  68,  69,  70, 244,   1, 
      0,   0,   1,   0,   0,   0, 
     68,   1,   0,   0,   7,   0, 
      0,   0,  28,   0,   0,   0, 
      0,   4, 255, 255,  16,   1, 
      0,   0, 194,   1,   0,   0, 
    252,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  11,   1,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  26,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     41,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  12,   0, 
      0,   0,  46,   1,   0,   0, 
      2,   0,   0,   0,   5,   0, 
      0,   0,   4,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     12,   0,   0,   0,  51,   1, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
     56,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 108, 105, 110, 101, 
     97, 114,  83,  97, 109, 112, 
    108, 101, 114,  49,   0, 108, 
    105, 110, 101,  97, 114,  83, 
     97, 109, 112, 108, 101, 114, 
     50,   0, 108, 105, 110, 101, 
     97, 114,  83,  97, 109, 112, 
    108, 101, 114,  51,   0, 116, 
    101, 120,  49,   0, 116, 101, 
    120,  50,   0, 116, 101, 120, 
     51,   0,  99, 111, 110, 115, 
    116,  97, 110, 116, 115,   0, 
    171, 171,  56,   1,   0,   0, 
      2,   0,   0,   0,  92,   1, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 140,   1,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    164,   1,   0,   0,   0,   0, 
      0,   0, 180,   1,   0,   0, 
     16,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
    164,   1,   0,   0,   0,   0, 
      0,   0, 115, 116, 101, 110, 
     99, 105, 108,  67, 111, 109, 
    112, 111, 110, 101, 110, 116, 
     66,  97, 115, 101, 100,   0, 
    171, 171,   0,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    115, 116, 114,  97, 105, 103, 
    104, 116,  65, 108, 112, 104, 
     97,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  50,  57,  46, 
     57,  53,  50,  46,  51,  49, 
     49,  49,   0, 171,  73,  83, 
     71,  78, 156,   0,   0,   0, 
      5,   0,   0,   0,   8,   0, 
      0,   0, 128,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 140,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,  15, 
      0,   0, 146,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,   3, 
      0,   0, 146,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,  12,  12, 
      0,   0, 146,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   3,   3, 
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
