--- glib/gstrfuncs.c.orig	2022-11-22 12:36:21.862769000 +0000
+++ glib/gstrfuncs.c	2022-11-22 12:36:45.836278000 +0000
@@ -326,7 +326,7 @@
 static locale_t
 get_C_locale (void)
 {
-  static gsize initialized = FALSE;
+  static gintptr initialized = FALSE;
   static locale_t C_locale = NULL;
 
   if (g_once_init_enter (&initialized))
