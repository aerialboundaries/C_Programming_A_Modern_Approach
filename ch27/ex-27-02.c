/*
(C99) Write the parameterized macros INT32_C(n), UINT32_C(n), INT64_C(n), and
UINT64_C(n), assuming that the int type and long int types are 32 bits wide and
the long long int type is 64 bits wide. Hint: Use the ## preprocessor operator
to attach a suffix to n containing a combination of L and/or U characters. (See
Section 7.1 for a discussion of how to use the L and U suffixes with integer
constants.)
*/
#include <stdint.h>
#include <stdio.h>

/* 標準ライブラリの定義と競合しないよう、一度解除するか別名にします */
#ifdef INT32_C
#undef INT32_C
#endif
#ifdef UINT32_C
#undef UINT32_C
#endif
#ifdef INT64_C
#undef INT64_C
#endif
#ifdef UINT64_C
#undef UINT64_C
#endif

/* 問題の条件に合わせた定数生成マクロの定義（引数にはサフィックスをつけません）
 */
#define INT32_C(n) (n##L)
#define UINT32_C(n) (n##UL)
#define INT64_C(n) (n##LL)
#define UINT64_C(n) (n##ULL)

int main(void)
{
  /* サフィックスのない整数を引数として渡します */
  int32_t i32 = INT32_C(123456);
  uint32_t u32 = UINT32_C(123456);
  int64_t i64 = INT64_C(1234567890);
  uint64_t u64 = UINT64_C(1234567890);

  printf("=== Integer Constant Macros Test ===\n");
  printf("INT32_C  : size = %zu bytes, value = %ld\n", sizeof(i32), (long)i32);
  printf("UINT32_C : size = %zu bytes, value = %lu\n", sizeof(u32),
         (unsigned long)u32);
  printf("INT64_C  : size = %zu bytes, value = %lld\n", sizeof(i64),
         (long long)i64);
  printf("UINT64_C : size = %zu bytes, value = %llu\n", sizeof(u64),
         (unsigned long long)u64);

  return 0;
}
