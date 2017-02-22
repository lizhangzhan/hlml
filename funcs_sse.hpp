#define HLML_INLINEF      __forceinline

namespace hlml {
HLML_INLINEF VF128 axbxayby(VF128 a, VF128 b) { return _mm_unpacklo_ps(a, b); }
HLML_INLINEF VF128 axaybxby(VF128 a, VF128 b) { return _mm_movelh_ps(a, b); }
HLML_INLINEF VF128 azbzawbw(VF128 a, VF128 b) { return _mm_unpackhi_ps(a, b); }
HLML_INLINEF VF128 bzbwazaw(VF128 a, VF128 b) { return _mm_movehl_ps(a, b); }
HLML_INLINEF VF128 setXYZW(F32 x, F32 y, F32 z, F32 w) { return _mm_set_ps(w, z, y, x); }
HLML_INLINEF VI128 setXYZW(I32 x, I32 y, I32 z, I32 w) { return _mm_set_epi32(w, z, y, x); }
HLML_INLINEF VF128 setXXXX(F32 x) { return _mm_set1_ps(x); }
HLML_INLINEF VI128 setXXXX(I32 x) { return _mm_set_epi32(x, x, x, x); }
HLML_INLINEF VF128 notAandB(VF128 a, VF128 b) { return _mm_andnot_ps(a, b); }
HLML_INLINEF VI128 notAandB(VI128 a, VI128 b) { return _mm_andnot_si128(a, b); }
HLML_INLINEF VF128 AandB(VF128 a, VF128 b) { return _mm_and_ps(a, b); }
HLML_INLINEF VI128 AandB(VI128 a, VI128 b) { return _mm_and_si128(a, b); }
HLML_INLINEF VF128 AorB(VF128 a, VF128 b) { return _mm_or_ps(a, b); }
HLML_INLINEF VI128 AorB(VI128 a, VI128 b) { return _mm_or_si128(a, b); }
HLML_INLINEF VF128 AxorB(VF128 a, VF128 b) { return _mm_xor_ps(a, b); }
HLML_INLINEF VI128 AxorB(VI128 a, VI128 b) { return _mm_xor_si128(a, b); }
HLML_INLINEF VF128 AaddB(VF128 a, VF128 b) { return _mm_add_ps(a, b); }
HLML_INLINEF VI128 AaddB(VI128 a, VI128 b) { return _mm_add_epi32(a, b); }
HLML_INLINEF VF128 AsubB(VF128 a, VF128 b) { return _mm_sub_ps(a, b); }
HLML_INLINEF VI128 AsubB(VI128 a, VI128 b) { return _mm_sub_epi32(a, b); }
HLML_INLINEF VF128 AmulB(VF128 a, VF128 b) { return _mm_mul_ps(a, b); }
HLML_INLINEF VI128 AmulB(VI128 a, VI128 b) { return _mm_mul_epi32(a, b); }
HLML_INLINEF VF128 AdivB(VF128 a, VF128 b) { return _mm_div_ps(a, b); }
HLML_INLINEF VF128 AcmpeqB(VF128 a, VF128 b) { return _mm_cmpeq_ps(a, b); }
HLML_INLINEF VI128 AcmpeqB(VI128 a, VI128 b) { return _mm_cmpeq_epi32(a, b); }
HLML_INLINEF VF128 AcmpneqB(VF128 a, VF128 b) { return _mm_cmpneq_ps(a, b); }
HLML_INLINEF VI128 AcmpneqB(VI128 a, VI128 b) { return notAandB(AcmpeqB(a, b), setXXXX(~0)); }
HLML_INLINEF VF128 AcmpltB(VF128 a, VF128 b) { return _mm_cmplt_ps(a, b); }
HLML_INLINEF VI128 AcmpltB(VI128 a, VI128 b) { return _mm_cmplt_epi32(a, b); }
HLML_INLINEF VF128 AcmpgeB(VF128 a, VF128 b) { return _mm_cmpge_ps(a, b); }
HLML_INLINEF VI128 AcmpgeB(VI128 a, VI128 b) { return notAandB(AcmpltB(a, b), setXXXX(~0)); }
HLML_INLINEF VF128 AcmpgtB(VF128 a, VF128 b) { return _mm_cmpgt_ps(a, b); }
HLML_INLINEF VI128 AcmpgtB(VI128 a, VI128 b) { return _mm_cmpgt_epi32(a, b); }
HLML_INLINEF VF128 AcmpleB(VF128 a, VF128 b) { return _mm_cmple_ps(a, b); }
HLML_INLINEF VI128 AcmpleB(VI128 a, VI128 b) { return notAandB(AcmpltB(a, b), setXXXX(~0)); }
HLML_INLINEF VF128 AminB(VF128 a, VF128 b) { return _mm_min_ps(a, b); }
HLML_INLINEF VI128 AminB(VI128 a, VI128 b) { return _mm_min_epi32(a, b); }
HLML_INLINEF VF128 AmaxB(VF128 a, VF128 b) { return _mm_max_ps(a, b); }
HLML_INLINEF VI128 AmaxB(VI128 a, VI128 b) { return _mm_max_epi32(a, b); }
HLML_INLINEF VF128 AhaddB(VF128 a, VF128 b) { return _mm_hadd_ps(a, b); }
HLML_INLINEF VI128 AhaddB(VI128 a, VI128 b) { return _mm_hadd_epi32(a, b); }
HLML_INLINEF VI128 Ashiftl(VI128 a, U8 bits) { return _mm_slli_epi32(a, bits); }
HLML_INLINEF VI128 Ashiftr(VI128 a, U8 bits) { return _mm_srli_epi32(a, bits); }
HLML_INLINEF I32 movemask(VI128 a) { return _mm_movemask_epi8(a); }
HLML_INLINEF VI128 ftoi(VF128 a) { return _mm_cvttps_epi32(a); }
HLML_INLINEF VI128 ftoi(VI128 a) { return a; }
HLML_INLINEF VF128 itof(VI128 a) { return _mm_cvtepi32_ps(a); }
HLML_INLINEF VF128 itof(VF128 a) { return a; }
HLML_INLINEF VI128 fasi(VF128 a) { return _mm_castps_si128(a); }
HLML_INLINEF VI128 fasi(VI128 a) { return a; }
HLML_INLINEF VF128 iasf(VI128 a) { return _mm_castsi128_ps(a); }
HLML_INLINEF VF128 iasf(VF128 a) { return a; }

HLML_INLINEF VF128 rcp(VF128 a) { return _mm_rcp_ps(a); }
HLML_INLINEF VF128 sqrt(VF128 a) { return _mm_sqrt_ps(a); }
HLML_INLINEF VF128 rsqrt(VF128 a) { return _mm_rsqrt_ps(a); }
HLML_INLINEF VF128 mulABaddC(VF128 a, VF128 b, VF128 c) { return _mm_fmadd_ps(a, b, c); }
HLML_INLINEF VF128 floor(VF128 a) { return _mm_floor_ps(a); }
HLML_INLINEF VF128 ceil(VF128 a) { return _mm_ceil_ps(a); }
HLML_INLINEF VF128 trunc(VF128 a) { return _mm_round_ps(a, _MM_FROUND_TRUNC); }
HLML_INLINEF VF128 round(VF128 a) { return _mm_round_ps(a, _MM_FROUND_NINT); }
HLML_INLINEF VF128 frac(VF128 a) { return _mm_frcz_ps(a); }
}