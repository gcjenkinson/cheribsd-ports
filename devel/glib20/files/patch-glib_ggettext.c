--- glib/ggettext.c.orig	2022-11-22 11:13:15.255274000 +0000
+++ glib/ggettext.c	2022-11-22 11:18:40.085322000 +0000
@@ -95,7 +95,7 @@
 static void
 ensure_gettext_initialized (void)
 {
-  static gsize initialised;
+  static gintptr initialised;
 
   if (g_once_init_enter (&initialised))
     {
@@ -302,7 +302,7 @@
 static gboolean
 _g_dgettext_should_translate (void)
 {
-  static gsize translate = 0;
+  static gintptr translate = 0;
   enum {
     SHOULD_TRANSLATE = 1,
     SHOULD_NOT_TRANSLATE = 2
