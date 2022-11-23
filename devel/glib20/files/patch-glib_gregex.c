--- glib/gregex.c.orig	2022-11-22 12:33:05.893446000 +0000
+++ glib/gregex.c	2022-11-22 12:33:27.756675000 +0000
@@ -1305,7 +1305,7 @@
   pcre *re;
   const gchar *errmsg;
   gboolean optimize = FALSE;
-  static gsize initialised = 0;
+  static gintptr initialised = 0;
 
   g_return_val_if_fail (pattern != NULL, NULL);
   g_return_val_if_fail (error == NULL || *error == NULL, NULL);
