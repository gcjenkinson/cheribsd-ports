--- glib/gdataset.c.orig	2022-11-22 11:25:16.503417000 +0000
+++ glib/gdataset.c	2022-11-22 12:21:51.746221000 +0000
@@ -31,6 +31,8 @@
 
 #include "config.h"
 
+#include <assert.h>
+#include <cheri.h>
 #include <string.h>
 
 #include "gdataset.h"
@@ -139,13 +141,15 @@
 
 /* datalist pointer accesses have to be carried out atomically */
 #define G_DATALIST_GET_POINTER(datalist)						\
-  ((GData*) ((gsize) g_atomic_pointer_get (datalist) & ~(gsize) G_DATALIST_FLAGS_MASK_INTERNAL))
+  ((GData *) cheri_low_bits_clear((intptr_t) g_atomic_pointer_get (datalist), (vaddr_t) G_DATALIST_FLAGS_MASK_INTERNAL)) 
 
 #define G_DATALIST_SET_POINTER(datalist, pointer)       G_STMT_START {                  \
   gpointer _oldv, _newv;                                                                \
+  vaddr_t _oldv_datalist_flags;                                                         \
   do {                                                                                  \
     _oldv = g_atomic_pointer_get (datalist);                                            \
-    _newv = (gpointer) (((gsize) _oldv & G_DATALIST_FLAGS_MASK_INTERNAL) | (gsize) pointer);     \
+    _oldv_datalist_flags = cheri_low_bits_get((intptr_t) _oldv, (vaddr_t) G_DATALIST_FLAGS_MASK_INTERNAL);	\
+    _newv = (gpointer) cheri_low_bits_or((intptr_t) pointer, _oldv_datalist_flags);                          	\
   } while (!g_atomic_pointer_compare_and_exchange ((void**) datalist, _oldv, _newv));   \
 } G_STMT_END
 
