#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /D SWRAP=1 /D TWRAP=1 /nologo /Zpc /Tps_4_0_level_9_3
//    /Dop_main=FilterConvolve25Bias /EFilterConvolve25Bias
//    /FhFilterConvolve25Bias_REPEAT_REPEAT_level9_3.h /Vn
//    g_ps20_FilterConvolve25Bias_REPEAT_REPEAT convolve_gen_25_bias.psh
//
//
// Buffer Definitions: 
//
// cbuffer constants
// {
//
//   float3 offsetWeight[25];           // Offset:    0 Size:   396
//   float divisor;                     // Offset:  400 Size:     4
//   float bias;                        // Offset:  416 Size:     4
//   bool preserve_alpha;               // Offset:  432 Size:     4
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// srcSampler                        sampler      NA          NA    0        1
// srcTex                            texture  float4          2d    0        1
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
// c0         cb0             0        27  ( FLT, FLT, FLT, FLT)
// c27        cb0            27         1  (BOOL, FLT, FLT, FLT)
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
    ps_2_x
    dcl t1.xy
    dcl_2d s0
    add r0.xy, t1, c1
    frc r0.xy, r0
    add r0.zw, t1.xyxy, c0.xyxy
    frc r1.xy, r0.zwzw
    texld r0, r0, s0
    texld r1, r1, s0
    mul r0, r0, c1.z
    mad r0, r1, c0.z, r0
    add r1.xy, t1, c2
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c3.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c2.z, r0
    mad r0, r2, c3.z, r0
    add r1.xy, t1, c4
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c5.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c4.z, r0
    mad r0, r2, c5.z, r0
    add r1.xy, t1, c6
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c7.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c6.z, r0
    mad r0, r2, c7.z, r0
    add r1.xy, t1, c8
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c9.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c8.z, r0
    mad r0, r2, c9.z, r0
    add r1.xy, t1, c10
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c11.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c10.z, r0
    mad r0, r2, c11.z, r0
    add r1.xy, t1, c12
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c13.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c12.z, r0
    mad r0, r2, c13.z, r0
    add r1.xy, t1, c14
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c15.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c14.z, r0
    mad r0, r2, c15.z, r0
    add r1.xy, t1, c16
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c17.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c16.z, r0
    mad r0, r2, c17.z, r0
    add r1.xy, t1, c18
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c19.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c18.z, r0
    mad r0, r2, c19.z, r0
    add r1.xy, t1, c20
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c21.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c20.z, r0
    mad r0, r2, c21.z, r0
    add r1.xy, t1, c22
    frc r1.xy, r1
    add r1.zw, t1.xyxy, c23.xyxy
    frc r2.xy, r1.zwzw
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c22.z, r0
    mad r0, r2, c23.z, r0
    add r1.xy, t1, c24
    frc r1.xy, r1
    frc r2.xy, t1
    texld r1, r1, s0
    texld r2, r2, s0
    mad r0, r1, c24.z, r0
    rcp r1.x, c25.x
    mad r0, r0, r1.x, c26.x
    rcp r1.x, r0.w
    mul r1.xyz, r0, r1.x
    cmp r1.xyz, -r0.w, r0, r1
    mul r2.xyz, r2.w, r1
    cmp_sat r0, -c27.x, r0, r2
    mov oC0, r0

// approximately 110 instruction slots used (26 texture, 84 arithmetic)
ps_4_0
dcl_constantbuffer cb0[28], dynamicIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v2.xy
dcl_output o0.xyzw
dcl_temps 3
mov r0.xyzw, l(0,0,0,0)
mov r1.x, l(0)
loop 
  ige r1.y, r1.x, l(25)
  breakc_nz r1.y
  add r1.yz, v2.xxyx, cb0[r1.x + 0].xxyx
  frc r1.yz, r1.yyzy
  sample r2.xyzw, r1.yzyy, t0.xyzw, s0
  mad r0.xyzw, r2.xyzw, cb0[r1.x + 0].zzzz, r0.xyzw
  iadd r1.x, r1.x, l(1)
endloop 
div r0.xyzw, r0.xyzw, cb0[25].xxxx
add r0.xyzw, r0.xyzw, cb0[26].xxxx
if_nz cb0[27].x
  frc r1.xy, v2.xyxx
  sample r1.xyzw, r1.xyxx, t0.xyzw, s0
  ge r1.x, l(0.000000), r0.w
  div r2.xyz, r0.xyzx, r0.wwww
  movc r1.xyz, r1.xxxx, r0.xyzx, r2.xyzx
  mul r0.xyz, r1.wwww, r1.xyzx
  mov r0.w, r1.w
endif 
mov_sat o0.xyzw, r0.xyzw
ret 
// Approximately 24 instruction slots used
#endif

const BYTE g_ps20_FilterConvolve25Bias_REPEAT_REPEAT[] =
{
     68,  88,  66,  67,  76,  20, 
    226,  29, 149, 180,  96, 253, 
    120, 254, 228,  60, 140,  87, 
     65, 135,   1,   0,   0,   0, 
    216,  12,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
    120,   7,   0,   0,  12,  10, 
      0,   0, 136,  10,   0,   0, 
     48,  12,   0,   0, 164,  12, 
      0,   0,  65, 111, 110,  57, 
     56,   7,   0,   0,  56,   7, 
      0,   0,   0,   2, 255, 255, 
    248,   6,   0,   0,  64,   0, 
      0,   0,   2,   0,  40,   0, 
      0,   0,  64,   0,   0,   0, 
     64,   0,   1,   0,  36,   0, 
      0,   0,  64,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     27,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  27,   0, 
      1,   0,  27,   0,   1,   0, 
      0,   0,   1,   2, 255, 255, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   1,   0,   3, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
      2,   0,   0,   3,   0,   0, 
      3, 128,   1,   0, 228, 176, 
      1,   0, 228, 160,  19,   0, 
      0,   2,   0,   0,   3, 128, 
      0,   0, 228, 128,   2,   0, 
      0,   3,   0,   0,  12, 128, 
      1,   0,  68, 176,   0,   0, 
     68, 160,  19,   0,   0,   2, 
      1,   0,   3, 128,   0,   0, 
    238, 128,  66,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   0,   8, 228, 160, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      0,   8, 228, 160,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   1,   0, 
    170, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   1,   0, 
    228, 128,   0,   0, 170, 160, 
      0,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,   3, 128, 
      1,   0, 228, 176,   2,   0, 
    228, 160,  19,   0,   0,   2, 
      1,   0,   3, 128,   1,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,  12, 128,   1,   0, 
     68, 176,   3,   0,  68, 160, 
     19,   0,   0,   2,   2,   0, 
      3, 128,   1,   0, 238, 128, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      0,   8, 228, 160,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   0,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   1,   0, 
    228, 128,   2,   0, 170, 160, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      2,   0, 228, 128,   3,   0, 
    170, 160,   0,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
      3, 128,   1,   0, 228, 176, 
      4,   0, 228, 160,  19,   0, 
      0,   2,   1,   0,   3, 128, 
      1,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,  12, 128, 
      1,   0,  68, 176,   5,   0, 
     68, 160,  19,   0,   0,   2, 
      2,   0,   3, 128,   1,   0, 
    238, 128,  66,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    228, 128,   0,   8, 228, 160, 
     66,   0,   0,   3,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      0,   8, 228, 160,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      1,   0, 228, 128,   4,   0, 
    170, 160,   0,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   2,   0, 228, 128, 
      5,   0, 170, 160,   0,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,   3, 128,   1,   0, 
    228, 176,   6,   0, 228, 160, 
     19,   0,   0,   2,   1,   0, 
      3, 128,   1,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
     12, 128,   1,   0,  68, 176, 
      7,   0,  68, 160,  19,   0, 
      0,   2,   2,   0,   3, 128, 
      1,   0, 238, 128,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   0,   8, 
    228, 160,  66,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,   0,   8, 228, 160, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   1,   0, 228, 128, 
      6,   0, 170, 160,   0,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,  15, 128,   2,   0, 
    228, 128,   7,   0, 170, 160, 
      0,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,   3, 128, 
      1,   0, 228, 176,   8,   0, 
    228, 160,  19,   0,   0,   2, 
      1,   0,   3, 128,   1,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,  12, 128,   1,   0, 
     68, 176,   9,   0,  68, 160, 
     19,   0,   0,   2,   2,   0, 
      3, 128,   1,   0, 238, 128, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      0,   8, 228, 160,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   0,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   1,   0, 
    228, 128,   8,   0, 170, 160, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      2,   0, 228, 128,   9,   0, 
    170, 160,   0,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
      3, 128,   1,   0, 228, 176, 
     10,   0, 228, 160,  19,   0, 
      0,   2,   1,   0,   3, 128, 
      1,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,  12, 128, 
      1,   0,  68, 176,  11,   0, 
     68, 160,  19,   0,   0,   2, 
      2,   0,   3, 128,   1,   0, 
    238, 128,  66,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    228, 128,   0,   8, 228, 160, 
     66,   0,   0,   3,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      0,   8, 228, 160,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      1,   0, 228, 128,  10,   0, 
    170, 160,   0,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   2,   0, 228, 128, 
     11,   0, 170, 160,   0,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,   3, 128,   1,   0, 
    228, 176,  12,   0, 228, 160, 
     19,   0,   0,   2,   1,   0, 
      3, 128,   1,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
     12, 128,   1,   0,  68, 176, 
     13,   0,  68, 160,  19,   0, 
      0,   2,   2,   0,   3, 128, 
      1,   0, 238, 128,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   0,   8, 
    228, 160,  66,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,   0,   8, 228, 160, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   1,   0, 228, 128, 
     12,   0, 170, 160,   0,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,  15, 128,   2,   0, 
    228, 128,  13,   0, 170, 160, 
      0,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,   3, 128, 
      1,   0, 228, 176,  14,   0, 
    228, 160,  19,   0,   0,   2, 
      1,   0,   3, 128,   1,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,  12, 128,   1,   0, 
     68, 176,  15,   0,  68, 160, 
     19,   0,   0,   2,   2,   0, 
      3, 128,   1,   0, 238, 128, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      0,   8, 228, 160,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   0,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   1,   0, 
    228, 128,  14,   0, 170, 160, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      2,   0, 228, 128,  15,   0, 
    170, 160,   0,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
      3, 128,   1,   0, 228, 176, 
     16,   0, 228, 160,  19,   0, 
      0,   2,   1,   0,   3, 128, 
      1,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,  12, 128, 
      1,   0,  68, 176,  17,   0, 
     68, 160,  19,   0,   0,   2, 
      2,   0,   3, 128,   1,   0, 
    238, 128,  66,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    228, 128,   0,   8, 228, 160, 
     66,   0,   0,   3,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      0,   8, 228, 160,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      1,   0, 228, 128,  16,   0, 
    170, 160,   0,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   2,   0, 228, 128, 
     17,   0, 170, 160,   0,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,   3, 128,   1,   0, 
    228, 176,  18,   0, 228, 160, 
     19,   0,   0,   2,   1,   0, 
      3, 128,   1,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
     12, 128,   1,   0,  68, 176, 
     19,   0,  68, 160,  19,   0, 
      0,   2,   2,   0,   3, 128, 
      1,   0, 238, 128,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   0,   8, 
    228, 160,  66,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,   0,   8, 228, 160, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   1,   0, 228, 128, 
     18,   0, 170, 160,   0,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,  15, 128,   2,   0, 
    228, 128,  19,   0, 170, 160, 
      0,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,   3, 128, 
      1,   0, 228, 176,  20,   0, 
    228, 160,  19,   0,   0,   2, 
      1,   0,   3, 128,   1,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,  12, 128,   1,   0, 
     68, 176,  21,   0,  68, 160, 
     19,   0,   0,   2,   2,   0, 
      3, 128,   1,   0, 238, 128, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      0,   8, 228, 160,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   0,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   1,   0, 
    228, 128,  20,   0, 170, 160, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      2,   0, 228, 128,  21,   0, 
    170, 160,   0,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
      3, 128,   1,   0, 228, 176, 
     22,   0, 228, 160,  19,   0, 
      0,   2,   1,   0,   3, 128, 
      1,   0, 228, 128,   2,   0, 
      0,   3,   1,   0,  12, 128, 
      1,   0,  68, 176,  23,   0, 
     68, 160,  19,   0,   0,   2, 
      2,   0,   3, 128,   1,   0, 
    238, 128,  66,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    228, 128,   0,   8, 228, 160, 
     66,   0,   0,   3,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      0,   8, 228, 160,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      1,   0, 228, 128,  22,   0, 
    170, 160,   0,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   2,   0, 228, 128, 
     23,   0, 170, 160,   0,   0, 
    228, 128,   2,   0,   0,   3, 
      1,   0,   3, 128,   1,   0, 
    228, 176,  24,   0, 228, 160, 
     19,   0,   0,   2,   1,   0, 
      3, 128,   1,   0, 228, 128, 
     19,   0,   0,   2,   2,   0, 
      3, 128,   1,   0, 228, 176, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      0,   8, 228, 160,  66,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   0,   8, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   1,   0, 
    228, 128,  24,   0, 170, 160, 
      0,   0, 228, 128,   6,   0, 
      0,   2,   1,   0,   1, 128, 
     25,   0,   0, 160,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      0,   0, 228, 128,   1,   0, 
      0, 128,  26,   0,   0, 160, 
      6,   0,   0,   2,   1,   0, 
      1, 128,   0,   0, 255, 128, 
      5,   0,   0,   3,   1,   0, 
      7, 128,   0,   0, 228, 128, 
      1,   0,   0, 128,  88,   0, 
      0,   4,   1,   0,   7, 128, 
      0,   0, 255, 129,   0,   0, 
    228, 128,   1,   0, 228, 128, 
      5,   0,   0,   3,   2,   0, 
      7, 128,   2,   0, 255, 128, 
      1,   0, 228, 128,  88,   0, 
      0,   4,   0,   0,  31, 128, 
     27,   0,   0, 161,   0,   0, 
    228, 128,   2,   0, 228, 128, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0,  83,  72, 
     68,  82, 140,   2,   0,   0, 
     64,   0,   0,   0, 163,   0, 
      0,   0,  89,   8,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  28,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   3,   0,   0,   0, 
     54,   0,   0,   8, 242,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
     18,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  48,   0, 
      0,   1,  33,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,  25,   0,   0,   0, 
      3,   0,   4,   3,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   9,  98,   0, 
     16,   0,   1,   0,   0,   0, 
      6,  17,  16,   0,   2,   0, 
      0,   0,   6, 129,  32,   4, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,   0,   5,  98,   0, 
     16,   0,   1,   0,   0,   0, 
     86,   6,  16,   0,   1,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   2,   0, 
      0,   0, 150,   5,  16,   0, 
      1,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,  11, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0, 166, 138, 
     32,   4,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   1,   0, 
      0,   0,  22,   0,   0,   1, 
     14,   0,   0,   8, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,  25,   0, 
      0,   0,   0,   0,   0,   8, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
     26,   0,   0,   0,  31,   0, 
      4,   4,  10, 128,  32,   0, 
      0,   0,   0,   0,  27,   0, 
      0,   0,  26,   0,   0,   5, 
     50,   0,  16,   0,   1,   0, 
      0,   0,  70,  16,  16,   0, 
      2,   0,   0,   0,  69,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 126,  16,   0,   0,   0, 
      0,   0,   0,  96,  16,   0, 
      0,   0,   0,   0,  29,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  14,   0,   0,   7, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   2,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   1,   0,   0,   0, 
     21,   0,   0,   1,  54,  32, 
      0,   5, 242,  32,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     24,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  82,  68,  69,  70, 
    160,   1,   0,   0,   1,   0, 
      0,   0, 152,   0,   0,   0, 
      3,   0,   0,   0,  28,   0, 
      0,   0,   0,   4, 255, 255, 
     16,   1,   0,   0, 108,   1, 
      0,   0, 124,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 135,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  12,   0,   0,   0, 
    142,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 115, 114,  99,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 115, 114,  99,  84, 101, 
    120,   0,  99, 111, 110, 115, 
    116,  97, 110, 116, 115,   0, 
    142,   0,   0,   0,   4,   0, 
      0,   0, 176,   0,   0,   0, 
    192,   1,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     16,   1,   0,   0,   0,   0, 
      0,   0, 140,   1,   0,   0, 
      2,   0,   0,   0,  32,   1, 
      0,   0,   0,   0,   0,   0, 
     48,   1,   0,   0, 144,   1, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  56,   1, 
      0,   0,   0,   0,   0,   0, 
     72,   1,   0,   0, 160,   1, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  56,   1, 
      0,   0,   0,   0,   0,   0, 
     77,   1,   0,   0, 176,   1, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  92,   1, 
      0,   0,   0,   0,   0,   0, 
    111, 102, 102, 115, 101, 116, 
     87, 101, 105, 103, 104, 116, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   3,   0, 
     25,   0,   0,   0,   0,   0, 
      0,   0, 100, 105, 118, 105, 
    115, 111, 114,   0,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  98, 105,  97, 115, 
      0, 112, 114, 101, 115, 101, 
    114, 118, 101,  95,  97, 108, 
    112, 104,  97,   0,   0,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  77, 105,  99, 114, 
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
     15,   0,   0,   0,  98,   0, 
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
