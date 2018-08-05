/* -*- Mode: c++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
 *
 * Copyright (C) 1995-2009 Opera Software AS.  All rights reserved.
 *
 * This file is part of the Opera web browser.  It may not be distributed
 * under any circumstances.
 *
 * THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!
 *
 */

#include "core/pch_system_includes.h"

#ifdef VEGA_BACKEND_OPENGL
#define VEGA_OPENGL_SHADERDATA_DEFINED

const char* g_GLSL_ShaderData[] = {
	// SHADER_VECTOR2D
	"uniform sampler2D src;\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"void main() {\n"
	" gl_FragColor = texture2D_wrap(src, vTexCoord0) * vert_color;\n"
	"}\n",

	// SHADER_VECTOR2DTEXGEN
	"uniform sampler2D src;\n"
	"uniform sampler2D stencilSrc;\n"
	"uniform sampler2D maskSrc;\n"
	"uniform bool stencilComponentBased;\n"
	"uniform bool straightAlpha;\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord2;\n"
	"varying vec2 vTexCoord3;\n"
	"const vec3 lumfactors = vec3(0.2125, 0.7154, 0.0721);\n"
	"void main() {\n"
	" vec4 stencil = texture2D(stencilSrc, vTexCoord2);\n"
	" if (stencilComponentBased)\n"
	" {\n"
	" float lum = dot(stencil.rgb, lumfactors);\n"
	" stencil = vec4(lum);\n"
	" }\n"
	" float maskAlpha = texture2D(maskSrc, vTexCoord3).a;\n"
	" float maskColor = max(float(straightAlpha), maskAlpha);\n"
	" vec4 mask = vec4(maskColor, maskColor, maskColor, maskAlpha);\n"
	" gl_FragColor = texture2D_wrap(src, vTexCoord0) * stencil * mask * vert_color;\n"
	"}\n",

	// SHADER_VECTOR2DTEXGENRADIAL
	"uniform sampler2D src;\n"
	"uniform sampler2D stencilSrc;\n"
	"uniform sampler2D maskSrc;\n"
	"uniform bool stencilComponentBased;\n"
	"uniform bool straightAlpha;\n"
	"uniform float uSrcY;\n"
	"uniform vec3 uFocusPoint; \n"
	"uniform vec3 uCenterPoint; \n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord2;\n"
	"varying vec2 vTexCoord3;\n"
	"const vec3 lumfactors = vec3(0.2125, 0.7154, 0.0721);\n"
	"void main() {\n"
	" vec3 cd = uCenterPoint - uFocusPoint;\n"
	" vec3 pd;\n"
	" pd.xy = vTexCoord0 - uFocusPoint.xy;\n"
	" pd.z = uFocusPoint.z;\n"
	" float a = dot(cd.xy, cd.xy) - cd.z*cd.z; \n"
	" float b = dot(pd, cd);\n"
	" float c = dot(pd.xy, pd.xy) - pd.z*pd.z;\n"
	" float offset;\n"
	" float scale = texture2D(maskSrc, vTexCoord3).a;\n"
	" if (abs(a) < 0.001)\n"
	" {\n"
	" offset = c / (2.0 * b);\n"
	" scale *= step(0.001, abs(b));\n"
	" }\n"
	" else\n"
	" {\n"
	" float bbac = b*b-a*c;\n"
	" scale *= step(0.0, bbac);\n"
	" bbac = sqrt(bbac) / a;\n"
	" b /= a;\n"
	" offset = b + bbac;\n"
	" offset -= step(offset*cd.z, -uFocusPoint.z)*2.0*bbac;\n"
	" }\n"
	" scale *= step(-uFocusPoint.z, offset*cd.z);\n"
	" vec4 stencil = texture2D(stencilSrc, vTexCoord2);\n"
	" if (stencilComponentBased)\n"
	" {\n"
	" float lum = dot(stencil.rgb, lumfactors);\n"
	" stencil = vec4(lum);\n"
	" }\n"
	" float maskColor = max(float(straightAlpha), scale);\n"
	" vec4 mask = vec4(maskColor, maskColor, maskColor, scale);\n"
	" vec4 col = texture2D(src, vec2(offset, uSrcY)) * stencil * mask * vert_color;\n"
	" gl_FragColor = col;\n"
	"}\n",

	// SHADER_VECTOR2DTEXGENRADIALSIMPLE
	"#ifdef GL_ES\n"
	"precision mediump float;\n"
	"#endif\n"
	"uniform sampler2D src;\n"
	"uniform sampler2D stencilSrc;\n"
	"uniform sampler2D maskSrc;\n"
	"uniform bool stencilComponentBased;\n"
	"uniform bool straightAlpha;\n"
	"uniform float uSrcY;\n"
	"uniform vec3 uFocusPoint; \n"
	"uniform vec3 uCenterPoint; \n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord2;\n"
	"varying vec2 vTexCoord3;\n"
	"const vec3 lumfactors = vec3(0.2125, 0.7154, 0.0721);\n"
	"void main() {\n"
	" vec2 cd = uCenterPoint.xy - uFocusPoint.xy;\n"
	" vec2 pd = vTexCoord0 - uFocusPoint.xy;\n"
	" float offset;\n"
	" float scale = texture2D(maskSrc, vTexCoord3).a;\n"
	" scale *= uFocusPoint.z < 0.001 ? 1.0 : 0.0;\n"
	" float rr = uCenterPoint.z*uCenterPoint.z;\n"
	" float pdp = dot(pd.xy, pd.xy);\n"
	" if (all(equal(uFocusPoint.xy, uCenterPoint.xy)))\n"
	" {\n"
	" offset = sqrt(pdp/rr);\n"
	" }\n"
	" else\n"
	" {\n"
	" float ppc = pd.x*cd.y - pd.y*cd.x;\n"
	" float pdc = dot(pd.xy, cd.xy);\n"
	" offset = pdp / (pdc + sqrt(rr * pdp - ppc*ppc));\n"
	" }\n"
	" vec4 stencil = texture2D(stencilSrc, vTexCoord2);\n"
	" if (stencilComponentBased)\n"
	" {\n"
	" float lum = dot(stencil.rgb, lumfactors);\n"
	" stencil = vec4(lum);\n"
	" }\n"
	" float maskColor = max(float(straightAlpha), scale);\n"
	" vec4 mask = vec4(maskColor, maskColor, maskColor, scale);\n"
	" vec4 col = texture2D(src, vec2(offset, uSrcY)) * stencil * mask * vert_color;\n"
	" gl_FragColor = col;\n"
	"}\n",

	// SHADER_TEXT2D
	"uniform sampler2D src;\n"
	"uniform vec4 alphaComponent;\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"void main() {\n"
	" float alpha = dot(texture2D(src, vTexCoord0), alphaComponent);\n"
	" gl_FragColor = vert_color * alpha;\n"
	"}\n",

	// SHADER_TEXT2DTEXGEN
	"uniform sampler2D src;\n"
	"uniform sampler2D stencilSrc;\n"
	"uniform vec4 alphaComponent;\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord2;\n"
	"void main() {\n"
	" float alpha = dot(texture2D(src, vTexCoord0), alphaComponent);\n"
	" gl_FragColor = vert_color * alpha * texture2D(stencilSrc, vTexCoord2);\n"
	"}\n",

	// SHADER_TEXT2DEXTBLEND
	"#version 130\n"
	"uniform sampler2D src;\n"
	"in vec4 vert_color;\n"
	"out vec4 fragColor0;\n"
	"out vec4 fragColor1;\n"
	"varying vec2 vTexCoord0;\n"
	"void main() {\n"
	" vec4 subpixel_alpha = texture2D(src, vTexCoord0);\n"
	" fragColor0 = vert_color * subpixel_alpha;\n"
	" fragColor1 = subpixel_alpha * vert_color.a;\n"
	"}\n",

	// SHADER_TEXT2DEXTBLENDTEXGEN
	"#version 130\n"
	"uniform sampler2D src;\n"
	"uniform sampler2D stencilSrc;\n"
	"in vec4 vert_color;\n"
	"out vec4 fragColor0;\n"
	"out vec4 fragColor1;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord2;\n"
	"void main() {\n"
	" vec4 subpixel_alpha = texture2D(src, vTexCoord0) * texture2D(stencilSrc, vTexCoord2);\n"
	" fragColor0 = vert_color * subpixel_alpha;\n"
	" fragColor1 = subpixel_alpha * vert_color.a;\n"
	"}\n",

	// SHADER_TEXT2D_INTERPOLATE
	"uniform sampler2D src;\n"
	"uniform sampler2D src2;\n"
	"uniform vec4 alphaComponent;\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"void main() {\n"
	" float intensity = dot(vert_color.rgb, vec3(0.2125, 0.7154, 0.0721))/vert_color.a;\n"
	" float alpha = dot(mix(texture2D(src, vTexCoord0), texture2D(src2, vTexCoord0), intensity), alphaComponent);\n"
	" gl_FragColor = vert_color * alpha;\n"
	"}\n",

	// SHADER_TEXT2DTEXGEN_INTERPOLATE
	"uniform sampler2D src;\n"
	"uniform sampler2D src2;\n"
	"uniform sampler2D stencilSrc;\n"
	"uniform vec4 alphaComponent;\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord2;\n"
	"void main() {\n"
	" float intensity = dot(vert_color.rgb, vec3(0.2125, 0.7154, 0.0721))/vert_color.a;\n"
	" float alpha = dot(mix(texture2D(src, vTexCoord0), texture2D(src2, vTexCoord0), intensity), alphaComponent);\n"
	" gl_FragColor = vert_color * alpha * texture2D(stencilSrc, vTexCoord2);\n"
	"}\n",

	// SHADER_TEXT2DEXTBLEND_INTERPOLATE
	"#version 130\n"
	"uniform sampler2D src;\n"
	"uniform sampler2D src2;\n"
	"in vec4 vert_color;\n"
	"out vec4 fragColor0;\n"
	"out vec4 fragColor1;\n"
	"varying vec2 vTexCoord0;\n"
	"void main() {\n"
	" float intensity = dot(vert_color.rgb, vec3(0.2125, 0.7154, 0.0721))/vert_color.a;\n"
	" vec4 subpixel_alpha = mix(texture2D(src, vTexCoord0), texture2D(src2, vTexCoord0), intensity);\n"
	" fragColor0 = vert_color * subpixel_alpha;\n"
	" fragColor1 = subpixel_alpha * vert_color.a;\n"
	"}\n",

	// SHADER_TEXT2DEXTBLENDTEXGEN_INTERPOLATE
	"#version 130\n"
	"uniform sampler2D src;\n"
	"uniform sampler2D src2;\n"
	"uniform sampler2D stencilSrc;\n"
	"in vec4 vert_color;\n"
	"out vec4 fragColor0;\n"
	"out vec4 fragColor1;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord2;\n"
	"void main() {\n"
	" float intensity = dot(vert_color.rgb, vec3(0.2125, 0.7154, 0.0721))/vert_color.a;\n"
	" vec4 subpixel_alpha = mix(texture2D(src, vTexCoord0), texture2D(src2, vTexCoord0), intensity) * texture2D(stencilSrc, vTexCoord2);\n"
	" fragColor0 = vert_color * subpixel_alpha;\n"
	" fragColor1 = subpixel_alpha * vert_color.a;\n"
	"}\n",

	// SHADER_COLORMATRIX
	"uniform sampler2D src;\n"
	"uniform mat4 colormat;\n"
	"uniform vec4 colorbias;\n"
	"varying vec2 vTexCoord0;\n"
	"vec4 unpremultiply(vec4 v)\n"
	"{\n"
	" return v.a <= 0.0 ? v : vec4(v.rgb / v.a, v.a);\n"
	"}\n"
	"vec4 premultiply(vec4 v)\n"
	"{\n"
	" float a = clamp(v.a, 0.0, 1.0);\n"
	" return vec4(v.rgb * a, a);\n"
	"}\n"
	"void main() {\n"
	" vec4 s = unpremultiply(texture2D(src, vTexCoord0));\n"
	" s = premultiply(s * colormat + colorbias);\n"
	" gl_FragColor = clamp(s, 0.0, 1.0);\n"
	"}\n",

	// SHADER_COMPONENTTRANSFER
	"uniform sampler2D src;\n"
	"uniform sampler2D map;\n"
	"varying vec2 vTexCoord0;\n"
	"vec4 unpremultiply(vec4 v)\n"
	"{\n"
	" return v.a <= 0.0 ? v : vec4(v.rgb / v.a, v.a);\n"
	"}\n"
	"vec4 premultiply(vec4 v)\n"
	"{\n"
	" return vec4(v.rgb * v.a, v.a);\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec4 c = unpremultiply(texture2D(src, vTexCoord0));\n"
	" c.r = texture2D(map, vec2(c.r, 0.0)).a;\n"
	" c.g = texture2D(map, vec2(c.g, 0.25)).a;\n"
	" c.b = texture2D(map, vec2(c.b, 0.5)).a;\n"
	" c.a = texture2D(map, vec2(c.a, 0.75)).a;\n"
	" gl_FragColor = premultiply(c);\n"
	"}\n",

	// SHADER_DISPLACEMENT
	"uniform sampler2D src;\n"
	"uniform sampler2D displace_map;\n"
	"uniform vec4 xselector;\n"
	"uniform vec4 yselector;\n"
	"uniform vec2 src_scale;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord1;\n"
	"float clampStep(vec2 texpos)\n"
	"{\n"
	"\treturn step(0, texpos.s) * step(texpos.s, 1) * step(0, texpos.t) * step(texpos.t, 1);\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec4 d = texture2D(displace_map, vTexCoord1);\n"
	" vec2 offset = vec2(dot(xselector, d), dot(yselector, d));\n"
	" offset = (offset - vec2(0.5, 0.5)) * src_scale;\n"
	" vec2 texpos = vTexCoord0 + offset;\n"
	" gl_FragColor = texture2D(src, texpos) * clampStep(texpos);\n"
	"}\n",

	// SHADER_LUMINANCE_TO_ALPHA
	"uniform sampler2D src;\n"
	"varying vec2 vTexCoord0;\n"
	"const vec3 lumfactors = vec3(0.2125, 0.7154, 0.0721);\n"
	"vec4 unpremultiply(vec4 v)\n"
	"{\n"
	" return v.a <= 0.0 ? v : vec4(v.rgb / v.a, v.a);\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec4 s = unpremultiply(texture2D(src, vTexCoord0));\n"
	" gl_FragColor = vec4(0.0, 0.0, 0.0, dot(s.rgb, lumfactors));\n"
	"}\n",

	// SHADER_SRGB_TO_LINEARRGB
	"uniform sampler2D src;\n"
	"const vec3 gamma = vec3(2.4, 2.4, 2.4);\n"
	"const vec3 offset = vec3(0.055, 0.055, 0.055);\n"
	"varying vec2 vTexCoord0;\n"
	"vec4 unpremultiply(vec4 v)\n"
	"{\n"
	" return v.a <= 0.0 ? v : vec4(v.rgb / v.a, v.a);\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec4 s = unpremultiply(texture2D(src, vTexCoord0));\n"
	" vec3 c = pow((s.rgb + offset) / 1.055, gamma);\n"
	" gl_FragColor = vec4(c * s.a, s.a);\n"
	"}\n",

	// SHADER_LINEARRGB_TO_SRGB
	"uniform sampler2D src;\n"
	"varying vec2 vTexCoord0;\n"
	"const vec3 invgamma = vec3(1.0/2.4, 1.0/2.4, 1.0/2.4);\n"
	"const vec3 offset = vec3(0.055, 0.055, 0.055);\n"
	"vec4 unpremultiply(vec4 v)\n"
	"{\n"
	" return v.a <= 0.0 ? v : vec4(v.rgb / v.a, v.a);\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec4 s = unpremultiply(texture2D(src, vTexCoord0));\n"
	" vec3 c = 1.055 * pow(s.rgb, invgamma) - offset;\n"
	" gl_FragColor = vec4(c * s.a, s.a);\n"
	"}\n",

	// SHADER_MERGE_ARITHMETIC
	"uniform sampler2D src1;\n"
	"uniform sampler2D src2;\n"
	"uniform float k1;\n"
	"uniform float k2;\n"
	"uniform float k3;\n"
	"uniform float k4;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord1;\n"
	"void main()\n"
	"{\n"
	" vec4 i1 = texture2D(src1, vTexCoord0);\n"
	" vec4 i2 = texture2D(src2, vTexCoord1);\n"
	" vec4 result = k1 * i1 * i2 + k2 * i1 + k3 * i2 + k4;\n"
	" gl_FragColor = clamp(result, 0.0, 1.0);\n"
	"}\n",

	// SHADER_MERGE_MULTIPLY
	"uniform sampler2D src1;\n"
	"uniform sampler2D src2;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord1;\n"
	"void main()\n"
	"{\n"
	" vec4 i1 = texture2D(src1, vTexCoord0);\n"
	" vec4 i2 = texture2D(src2, vTexCoord1);\n"
	" float qr = 1.0 - (1.0 - i1.a) * (1.0 - i2.a);\n"
	" vec3 cr = (1.0 - i1.a) * i2.rgb + (1.0 - i2.a) * i1.rgb + i1.rgb * i2.rgb;\n"
	" gl_FragColor = vec4(clamp(cr, 0.0, 1.0), qr);\n"
	"}\n",

	// SHADER_MERGE_SCREEN
	"uniform sampler2D src1;\n"
	"uniform sampler2D src2;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord1;\n"
	"void main()\n"
	"{\n"
	" vec4 i1 = texture2D(src1, vTexCoord0);\n"
	" vec4 i2 = texture2D(src2, vTexCoord1);\n"
	" vec4 result = i2 + i1 - i1 * i2;\n"
	" gl_FragColor = clamp(result, 0.0, 1.0);\n"
	"}\n",

	// SHADER_MERGE_DARKEN
	"uniform sampler2D src1;\n"
	"uniform sampler2D src2;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord1;\n"
	"void main()\n"
	"{\n"
	" vec4 i1 = texture2D(src1, vTexCoord0);\n"
	" vec4 i2 = texture2D(src2, vTexCoord1);\n"
	" float qr = 1.0 - (1.0 - i1.a) * (1.0 - i2.a);\n"
	" vec3 cr = min((1.0 - i1.a) * i2.rgb + i1.rgb, (1.0 - i2.a) * i1.rgb + i2.rgb);\n"
	" gl_FragColor = vec4(cr, qr);\n"
	"}\n",

	// SHADER_MERGE_LIGHTEN
	"uniform sampler2D src1;\n"
	"uniform sampler2D src2;\n"
	"varying vec2 vTexCoord0;\n"
	"varying vec2 vTexCoord1;\n"
	"void main()\n"
	"{\n"
	" vec4 i1 = texture2D(src1, vTexCoord0);\n"
	" vec4 i2 = texture2D(src2, vTexCoord1);\n"
	" float qr = 1.0 - (1.0 - i1.a) * (1.0 - i2.a);\n"
	" vec3 cr = max((1.0 - i1.a) * i2.rgb + i1.rgb, (1.0 - i2.a) * i1.rgb + i2.rgb);\n"
	" gl_FragColor = vec4(cr, qr);\n"
	"}\n",

	// SHADER_LIGHTING_DISTANTLIGHT
	"uniform sampler2D src;\n"
	"uniform vec3 light_color;\n"
	"uniform vec3 light_position;\n"
	"uniform float light_kd;\n"
	"uniform float light_ks;\n"
	"uniform float light_specexp;\n"
	"uniform float surface_scale;\n"
	"uniform float k1;\n"
	"uniform float k2;\n"
	"uniform float k3;\n"
	"uniform float k4;\n"
	"uniform vec2 pixel_size; \n"
	"varying vec2 vTexCoord0;\n"
	"const vec3 eye_vec = vec3(0.0, 0.0, 1.0);\n"
	"vec3 calc_surface_normal()\n"
	"{\n"
	" vec2 tc = vTexCoord0 + pixel_size * vec2(-1.0, -1.0);\n"
	" vec2 co = pixel_size * vec2(1.0, 0.0); \n"
	" vec2 ro = pixel_size * vec2(-2.0, 1.0); \n"
	" float c00 = texture2D(src, tc).a; tc += co;\n"
	" float c01 = texture2D(src, tc).a; tc += co;\n"
	" float c02 = texture2D(src, tc).a; tc += ro;\n"
	" float c10 = texture2D(src, tc).a; tc += co;\n"
	" tc += co;\n"
	" float c12 = texture2D(src, tc).a; tc += ro;\n"
	" float c20 = texture2D(src, tc).a; tc += co;\n"
	" float c21 = texture2D(src, tc).a; tc += co;\n"
	" float c22 = texture2D(src, tc).a;\n"
	" return normalize(vec3(-surface_scale * ((c02 + 2.0 * c12 + c22) - (c00 + 2.0 * c10 + c20)) / 4.0,\n"
	" -surface_scale * ((c20 + 2.0 * c21 + c22) - (c00 + 2.0 * c01 + c02)) / 4.0,\n"
	" 1.0));\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec3 n = calc_surface_normal();\n"
	" float n_dot_h = max(dot(n, normalize(light_position + eye_vec)), 0.0);\n"
	" float n_dot_l = max(dot(n, light_position), 0.0);\n"
	" vec3 specular_color = clamp(light_color * light_ks * pow(n_dot_h, light_specexp), 0.0, 1.0);\n"
	" vec3 diffuse_color = clamp(light_color * light_kd * n_dot_l, 0.0, 1.0);\n"
	" float alpha = max(specular_color.r, max(specular_color.g, specular_color.b));\n"
	" vec4 specular = vec4(specular_color * alpha, alpha);\n"
	" vec4 diffuse = vec4(diffuse_color, 1.0);\n"
	" vec4 combined = k1 * diffuse * specular + k2 * diffuse + k3 * specular + k4;\n"
	" gl_FragColor = clamp(combined, 0.0, 1.0);\n"
	"}\n",

	// SHADER_LIGHTING_POINTLIGHT
	"uniform sampler2D src;\n"
	"uniform vec3 light_color;\n"
	"uniform vec3 light_position;\n"
	"uniform float light_kd;\n"
	"uniform float light_ks;\n"
	"uniform float light_specexp;\n"
	"uniform float surface_scale;\n"
	"uniform float k1;\n"
	"uniform float k2;\n"
	"uniform float k3;\n"
	"uniform float k4;\n"
	"uniform vec2 pixel_size; \n"
	"varying vec2 vTexCoord0;\n"
	"const vec3 eye_vec = vec3(0.0, 0.0, 1.0);\n"
	"vec3 calc_surface_normal()\n"
	"{\n"
	" vec2 tc = vTexCoord0 + pixel_size * vec2(-1.0, -1.0);\n"
	" vec2 co = pixel_size * vec2(1.0, 0.0); \n"
	" vec2 ro = pixel_size * vec2(-2.0, 1.0); \n"
	" float c00 = texture2D(src, tc).a; tc += co;\n"
	" float c01 = texture2D(src, tc).a; tc += co;\n"
	" float c02 = texture2D(src, tc).a; tc += ro;\n"
	" float c10 = texture2D(src, tc).a; tc += co;\n"
	" tc += co;\n"
	" float c12 = texture2D(src, tc).a; tc += ro;\n"
	" float c20 = texture2D(src, tc).a; tc += co;\n"
	" float c21 = texture2D(src, tc).a; tc += co;\n"
	" float c22 = texture2D(src, tc).a;\n"
	" return normalize(vec3(-surface_scale * ((c02 + 2.0 * c12 + c22) - (c00 + 2.0 * c10 + c20)) / 4.0,\n"
	" -surface_scale * ((c20 + 2.0 * c21 + c22) - (c00 + 2.0 * c01 + c02)) / 4.0,\n"
	" 1.0));\n"
	"}\n"
	"void main()\n"
	"{\n"
	" float surf_height = texture2D(src, vTexCoord0).a * surface_scale;\n"
	" vec3 surf_pos = vec3(vTexCoord0 / pixel_size, surf_height);\n"
	" vec3 n = calc_surface_normal();\n"
	" vec3 l = normalize(light_position - surf_pos);\n"
	" float n_dot_l = max(dot(n, l), 0.0);\n"
	" float n_dot_h = max(dot(n, normalize(l + eye_vec)), 0.0);\n"
	" vec3 diffuse_color = clamp(light_color * light_kd * n_dot_l, 0.0, 1.0);\n"
	" vec4 diffuse = vec4(diffuse_color, 1.0);\n"
	" vec3 specular_color = clamp(light_color * light_ks * pow(n_dot_h, light_specexp), 0.0, 1.0);\n"
	" float alpha = max(specular_color.r, max(specular_color.g, specular_color.b));\n"
	" vec4 specular = vec4(specular_color * alpha, alpha);\n"
	" vec4 combined = k1 * diffuse * specular + k2 * diffuse + k3 * specular + k4;\n"
	" gl_FragColor = clamp(combined, 0.0, 1.0);\n"
	"}\n",

	// SHADER_LIGHTING_SPOTLIGHT
	"uniform sampler2D src;\n"
	"uniform vec3 light_color;\n"
	"uniform vec3 light_position;\n"
	"uniform float light_ks;\n"
	"uniform float light_kd;\n"
	"uniform float light_specexp;\n"
	"uniform vec3 spot_dir;\n"
	"uniform float spot_falloff;\n"
	"uniform float spot_coneangle;\n"
	"uniform float spot_specexp;\n"
	"uniform bool spot_has_cone;\n"
	"uniform float surface_scale;\n"
	"uniform float k1;\n"
	"uniform float k2;\n"
	"uniform float k3;\n"
	"uniform float k4;\n"
	"uniform vec2 pixel_size; \n"
	"varying vec2 vTexCoord0;\n"
	"const vec3 eye_vec = vec3(0.0, 0.0, 1.0);\n"
	"void main()\n"
	"{\n"
	" vec3 surf = (texture2D(src, vTexCoord0).xyz - vec3(0.5, 0.5, 0.0)) * surface_scale;\n"
	" vec3 surf_pos = vec3(vTexCoord0 / pixel_size, surf.z);\n"
	" vec3 n = normalize(vec3(-surf.xy, 1.0));\n"
	" vec3 l = normalize(light_position - surf_pos);\n"
	" float n_dot_l = max(dot(n, l), 0.0);\n"
	" float n_dot_h = max(dot(n, normalize(l + eye_vec)), 0.0);\n"
	" float l_dot_s = max(-dot(l, normalize(spot_dir)), 0.0);\n"
	" float spot_att = pow(l_dot_s, spot_specexp);\n"
	" if (spot_has_cone)\n"
	" spot_att = clamp(spot_att * (l_dot_s - spot_falloff) / (spot_coneangle - spot_falloff), 0.0, 1.0);\n"
	" vec3 diffuse_color = light_color * spot_att * clamp(light_kd * n_dot_l, 0.0, 1.0);\n"
	" vec4 diffuse = vec4(diffuse_color, 1.0);\n"
	" vec3 specular_color = light_color * spot_att * clamp(light_ks * pow(n_dot_h, light_specexp), 0.0, 1.0);\n"
	" float alpha = max(specular_color.r, max(specular_color.g, specular_color.b));\n"
	" vec4 specular = vec4(specular_color * alpha, alpha);\n"
	" vec4 combined = k1 * diffuse * specular + k2 * diffuse + k3 * specular + k4;\n"
	" gl_FragColor = clamp(combined, 0.0, 1.0);\n"
	"}\n",

	// SHADER_LIGHTING_MAKE_BUMP
	"uniform sampler2D src;\n"
	"uniform vec2 pixel_size; \n"
	"varying vec2 vTexCoord0;\n"
	"void main()\n"
	"{\n"
	" vec2 tc = vTexCoord0 - pixel_size;\n"
	" vec2 co = pixel_size * vec2(1.0, 0.0); \n"
	" vec2 ro = pixel_size * vec2(-2.0, 1.0); \n"
	" float c00 = texture2D(src, tc).a; tc += co;\n"
	" float c01 = texture2D(src, tc).a; tc += co;\n"
	" float c02 = texture2D(src, tc).a; tc += ro;\n"
	" float c10 = texture2D(src, tc).a; tc += co;\n"
	" tc += co;\n"
	" float c12 = texture2D(src, tc).a; tc += ro;\n"
	" float c20 = texture2D(src, tc).a; tc += co;\n"
	" float c21 = texture2D(src, tc).a; tc += co;\n"
	" float c22 = texture2D(src, tc).a;\n"
	" gl_FragColor = vec4(((c02 + 2.0 * c12 + c22) - (c00 + 2.0 * c10 + c20)) / 8.0 + 0.5,\n"
	" ((c20 + 2.0 * c21 + c22) - (c00 + 2.0 * c01 + c02)) / 8.0 + 0.5,\n"
	" texture2D(src, vTexCoord0).a,\n"
	" 0.0);\n"
	"}\n",

	// SHADER_CONVOLVE_GEN_16
	"uniform sampler2D src;\n"
	"uniform vec4 coeffs[16]; \n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"void main()\n"
	"{\n"
	" vec4 sum = vec4(0.0, 0.0, 0.0, 0.0);\n"
	" for (int i = 0; i < 16; ++i)\n"
	" {\n"
	" sum += texture2D_wrap(src, vTexCoord0 + coeffs[i].st) * coeffs[i].p;\n"
	" }\n"
	" gl_FragColor = sum*vert_color;\n"
	"}\n",

	// SHADER_CONVOLVE_GEN_16_BIAS
	"uniform sampler2D src;\n"
	"uniform vec4 coeffs[16]; \n"
	"uniform float divisor;\n"
	"uniform float bias;\n"
	"uniform bool preserve_alpha;\n"
	"varying vec2 vTexCoord0;\n"
	"vec4 unpremultiply(vec4 v)\n"
	"{\n"
	" return v.a <= 0.0 ? v : vec4(v.rgb / v.a, v.a);\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec4 sum = vec4(0.0, 0.0, 0.0, 0.0);\n"
	" for (int i = 0; i < 16; ++i)\n"
	" {\n"
	" sum += texture2D_wrap(src, vTexCoord0 + coeffs[i].st) * coeffs[i].p;\n"
	" }\n"
	" vec4 result = sum / divisor + bias;\n"
	" if (preserve_alpha)\n"
	" {\n"
	" vec4 orig = texture2D_wrap(src, vTexCoord0);\n"
	" result = unpremultiply(result);\n"
	" result = vec4(result.rgb * orig.a, orig.a);\n"
	" }\n"
	" gl_FragColor = clamp(result, 0.0, 1.0);\n"
	"}\n",

	// SHADER_CONVOLVE_GEN_25_BIAS
	"uniform sampler2D src;\n"
	"uniform vec4 coeffs[25]; \n"
	"uniform float divisor;\n"
	"uniform float bias;\n"
	"uniform bool preserve_alpha;\n"
	"varying vec2 vTexCoord0;\n"
	"vec4 unpremultiply(vec4 v)\n"
	"{\n"
	" return v.a <= 0.0 ? v : vec4(v.rgb / v.a, v.a);\n"
	"}\n"
	"void main()\n"
	"{\n"
	" vec4 sum = vec4(0.0, 0.0, 0.0, 0.0);\n"
	" for (int i = 0; i < 25; ++i)\n"
	" {\n"
	" sum += texture2D_wrap(src, vTexCoord0 + coeffs[i].st) * coeffs[i].p;\n"
	" }\n"
	" vec4 result = sum / divisor + bias;\n"
	" if (preserve_alpha)\n"
	" {\n"
	" vec4 orig = texture2D_wrap(src, vTexCoord0);\n"
	" result = unpremultiply(result);\n"
	" result = vec4(result.rgb * orig.a, orig.a);\n"
	" }\n"
	" gl_FragColor = clamp(result, 0.0, 1.0);\n"
	"}\n",

	// SHADER_MORPHOLOGY_DILATE_15
	"uniform sampler2D src;\n"
	"uniform vec4 offsets[7];\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"void main()\n"
	"{\n"
	" vec4 t = texture2D_wrap(src, vTexCoord0);\n"
	" for (int i = 0; i < 7; ++i)\n"
	" {\n"
	" t = max(t, texture2D_wrap(src, vTexCoord0 + offsets[i].st));\n"
	" t = max(t, texture2D_wrap(src, vTexCoord0 - offsets[i].st));\n"
	" }\n"
	" gl_FragColor = t*vert_color;\n"
	"}\n",

	// SHADER_MORPHOLOGY_ERODE_15
	"uniform sampler2D src;\n"
	"uniform vec4 offsets[7];\n"
	"varying vec4 vert_color;\n"
	"varying vec2 vTexCoord0;\n"
	"void main()\n"
	"{\n"
	" vec4 t = texture2D_wrap(src, vTexCoord0);\n"
	" for (int i = 0; i < 7; ++i)\n"
	" {\n"
	" t = min(t, texture2D_wrap(src, vTexCoord0 + offsets[i].st));\n"
	" t = min(t, texture2D_wrap(src, vTexCoord0 - offsets[i].st));\n"
	" }\n"
	" gl_FragColor = t*vert_color;\n"
	"}\n",

	// SHADER_CUSTOM
	NULL,

	// vert2d.shd
	"attribute vec4 inPosition;"
	"attribute vec2 inTex;"
	"attribute vec4 inColor;"
	"attribute vec2 inTex2;"
	"uniform mat4 worldProjMatrix;"
	"uniform vec4 texTransS[2];"
	"uniform vec4 texTransT[2];"
	"varying vec4 vert_color;"
	"varying vec2 vTexCoord0;"
	"varying vec2 vTexCoord1;"
	"varying vec2 vTexCoord2;"
	"varying vec2 vTexCoord3;"
	"void main() {"
	" gl_Position = worldProjMatrix * inPosition;"
	" vTexCoord0 = inTex;"
	" vTexCoord1 = inTex2;"
	" vTexCoord2.s = dot(texTransS[0], inPosition);"
	" vTexCoord2.t = dot(texTransT[0], inPosition);"
	" vTexCoord3.s = dot(texTransS[1], inPosition);"
	" vTexCoord3.t = dot(texTransT[1], inPosition);"
	" vert_color = inColor;"
	"}"
};

#endif // VEGA_BACKEND_OPENGL
