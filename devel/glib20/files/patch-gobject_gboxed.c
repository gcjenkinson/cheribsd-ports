--- gobject/gboxed.c.orig	2022-11-22 17:31:18.211123000 +0000
+++ gobject/gboxed.c	2022-11-22 17:31:48.279894000 +0000
@@ -182,7 +182,7 @@
 GType
 g_strv_get_type (void)
 {
-  static gsize static_g_define_type_id = 0;
+  static gintptr static_g_define_type_id = 0;
 
   if (g_once_init_enter (&static_g_define_type_id))
     {
