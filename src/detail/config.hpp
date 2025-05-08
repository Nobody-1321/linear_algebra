#pragma once

// ================================================
// Configuración manual (descomenta uno):
// ================================================
// #define LINE_FORCE_SCALAR
// #define LINE_FORCE_SSE
// #define LINE_FORCE_AVX2

// ================================================
// Auto-detección (si no se forzó nada):
// ================================================
#if !defined(LINE_FORCE_SCALAR) && !defined(LINE_FORCE_SSE)                   \
  && !defined(LINE_FORCE_AVX2)
#if defined(__AVX2__)
#define SIMD_USE_AVX2
#elif defined(__SSE__)
#define SIMD_USE_SSE
#else
#define SIMD_USE_SCALAR
#endif
#else
#if defined(LINE_FORCE_AVX2)
#define SIMD_USE_AVX2
#elif defined(LINE_FORCE_SSE)
#define SIMD_USE_SSE
#elif defined(LINE_FORCE_SCALAR)
#define SIMD_USE_SCALAR
#endif
#endif

// ================================================
// Etiquetas (Tags) para dispatch
// ================================================
struct ScalarImpl
{};
struct SSEImpl
{};
struct AVX2Impl
{};

#if defined(SIMD_USE_AVX2)
using SimdImpl = AVX2Impl;
#elif defined(SIMD_USE_SSE)
using SimdImpl = SSEImpl;
#else
using SimdImpl = ScalarImpl;
#endif
