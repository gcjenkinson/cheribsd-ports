--- gio/gportalsupport.c.orig	2022-11-23 15:52:09.187462000 +0000
+++ gio/gportalsupport.c	2022-11-23 15:52:24.502259000 +0000
@@ -27,7 +27,7 @@
 static void
 read_flatpak_info (void)
 {
-  static gsize flatpak_info_read = 0;
+  static gintptr flatpak_info_read = 0;
   const gchar *path = "/.flatpak-info";
 
   if (!g_once_init_enter (&flatpak_info_read))
