--- glib/gerror.h.orig	2022-11-22 12:56:23.988210000 +0000
+++ glib/gerror.h	2022-11-22 12:56:45.862529000 +0000
@@ -108,7 +108,7 @@
 error_type ## _quark (void)                                             \
 {                                                                       \
   static GQuark q;                                                      \
-  static gsize initialized = 0;                                         \
+  static gintptr initialized = 0;                                         \
                                                                         \
   if (g_once_init_enter (&initialized))                                 \
     {                                                                   \
