--- gobject/tests/signals.c.orig	2022-11-22 17:38:51.322525000 +0000
+++ gobject/tests/signals.c	2022-11-23 14:26:11.037879000 +0000
@@ -66,7 +66,7 @@
 static GType
 test_enum_get_type (void)
 {
-  static gsize static_g_define_type_id = 0;
+  static gintptr static_g_define_type_id = 0;
 
   if (g_once_init_enter (&static_g_define_type_id))
     {
@@ -88,7 +88,7 @@
 static GType
 test_unsigned_enum_get_type (void)
 {
-  static gsize static_g_define_type_id = 0;
+  static gintptr static_g_define_type_id = 0;
 
   if (g_once_init_enter (&static_g_define_type_id))
     {
