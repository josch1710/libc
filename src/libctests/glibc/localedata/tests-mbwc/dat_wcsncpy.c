/*
 *  TEST SUITE FOR MB/WC FUNCTIONS IN C LIBRARY
 *
 *       FILE:  dat_wcsncpy.c
 *
 *       WCSNCPY:  wchar_t *wcsncpy (wchar_t *ws1, const wchar_t *ws2,
 *                                   size_t n);
 */


/* Note:
 *
 *       An initial value of ws1 in the test program is defined as:
 *
 *       #define WCSNUM_NCPY 7
 *       wchar_t ws1 [WCSSIZE] = { 0x9999, 0x9999, 0x9999, 0x9999,
 *                                 0x9999, 0x9999, 0x0000 };
 * */


TST_WCSNCPY tst_wcsncpy_loc [] = {
  {
    {Twcsncpy, TST_LOC_de},
    {
      /* 1 */
      {{           { 0x00D1,0x00D2,0x00D3,0x0000                      }, 6 },
       {    0,0,0, { 0x00D1,0x00D2,0x00D3,0x0000,0x0000,0x0000,0x0000 }    },
      },
      /* 2 */
      {{           { 0x00D1,0x00D2,0x00D3,0x0000                      }, 5 },
       {    0,0,0, { 0x00D1,0x00D2,0x00D3,0x0000,0x0000,0x9999,0x0000 }    },
      },
      /* 3 */
      {{           { 0x00D1,0x00D2,0x00D3,0x0000                      }, 3 },
       {    0,0,0, { 0x00D1,0x00D2,0x00D3,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 4 */
      {{           { 0x00D1,0x00D2,0x00D3,0x0000                      }, 2 },
       {    0,0,0, { 0x00D1,0x00D2,0x9999,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 5 */
      {{           { 0x00D1,0x00D2,0x00D3,0x0000                      }, 0 },
       {    0,0,0, { 0x9999,0x9999,0x9999,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 6 */
      {{           { 0x0000,0x00D2,0x00D3,0x0000                      }, 3 },
       {    0,0,0, { 0x0000,0x0000,0x0000,0x9999,0x9999,0x9999,0x0000 }    },
      },
      {.is_last = 1}
    }
  },
  {
    {Twcsncpy, TST_LOC_enUS},
    {
      /* 1 */
      {{           { 0x0041,0x0042,0x0043,0x0000                      }, 6 },
       {    0,0,0, { 0x0041,0x0042,0x0043,0x0000,0x0000,0x0000,0x0000 }    },
      },
      /* 2 */
      {{           { 0x0041,0x0042,0x0043,0x0000                      }, 5 },
       {    0,0,0, { 0x0041,0x0042,0x0043,0x0000,0x0000,0x9999,0x0000 }    },
      },
      /* 3 */
      {{           { 0x0041,0x0042,0x0043,0x0000                      }, 3 },
       {    0,0,0, { 0x0041,0x0042,0x0043,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 4 */
      {{           { 0x0041,0x0042,0x0043,0x0000                      }, 2 },
       {    0,0,0, { 0x0041,0x0042,0x9999,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 5 */
      {{           { 0x0041,0x0042,0x0043,0x0000                      }, 0 },
       {    0,0,0, { 0x9999,0x9999,0x9999,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 6 */
      {{           { 0x0000,0x0042,0x0043,0x0000                      }, 3 },
       {    0,0,0, { 0x0000,0x0000,0x0000,0x9999,0x9999,0x9999,0x0000 }    },
      },
      {.is_last = 1}
    }
  },
  {
    {Twcsncpy, TST_LOC_eucJP},
    {
      /* 1 */
      {{           { 0x3041,0x3042,0x3043,0x0000                      }, 6 },
       {    0,0,0, { 0x3041,0x3042,0x3043,0x0000,0x0000,0x0000,0x0000 }    },
      },
      /* 2 */
      {{           { 0x3041,0x3042,0x3043,0x0000                      }, 5 },
       {    0,0,0, { 0x3041,0x3042,0x3043,0x0000,0x0000,0x9999,0x0000 }    },
      },
      /* 3 */
      {{           { 0x3041,0x3042,0x3043,0x0000                      }, 3 },
       {    0,0,0, { 0x3041,0x3042,0x3043,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 4 */
      {{           { 0x3041,0x3042,0x3043,0x0000                      }, 2 },
       {    0,0,0, { 0x3041,0x3042,0x9999,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 5 */
      {{           { 0x3041,0x3042,0x3043,0x0000                      }, 0 },
       {    0,0,0, { 0x9999,0x9999,0x9999,0x9999,0x9999,0x9999,0x0000 }    },
      },
      /* 6 */
      {{           { 0x0000,0x3042,0x3043,0x0000                      }, 3 },
       {    0,0,0, { 0x0000,0x0000,0x0000,0x9999,0x9999,0x9999,0x0000 }    },
      },
      {.is_last = 1}
    }
  },
  {
    {Twcsncpy, TST_LOC_end}
  }
};
