--- gio/gopenuriportal.c.orig	2022-11-23 15:46:04.327792000 +0000
+++ gio/gopenuriportal.c	2022-11-23 15:46:16.737544000 +0000
@@ -43,7 +43,7 @@
 static gboolean
 init_openuri_portal (void)
 {
-  static gsize openuri_inited = 0;
+  static gintptr openuri_inited = 0;
 
   if (g_once_init_enter (&openuri_inited))
     {
