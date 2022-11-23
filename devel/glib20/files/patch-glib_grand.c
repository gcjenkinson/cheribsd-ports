--- glib/grand.c.orig	2022-11-22 12:30:32.010547000 +0000
+++ glib/grand.c	2022-11-22 12:30:52.664097000 +0000
@@ -138,7 +138,7 @@
 static guint
 get_random_version (void)
 {
-  static gsize initialized = FALSE;
+  static gintptr initialized = FALSE;
   static guint random_version;
 
   if (g_once_init_enter (&initialized))
