--- gobject/gbinding.c.orig	2022-11-22 17:28:25.153375000 +0000
+++ gobject/gbinding.c	2022-11-22 17:28:40.203673000 +0000
@@ -121,7 +121,7 @@
 GType
 g_binding_flags_get_type (void)
 {
-  static gsize static_g_define_type_id = 0;
+  static gintptr static_g_define_type_id = 0;
 
   if (g_once_init_enter (&static_g_define_type_id))
     {
