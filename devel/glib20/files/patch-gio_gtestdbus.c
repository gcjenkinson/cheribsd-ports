--- gio/gtestdbus.c.orig	2022-11-23 15:49:17.275092000 +0000
+++ gio/gtestdbus.c	2022-11-23 15:49:40.040574000 +0000
@@ -119,7 +119,7 @@
 static void
 _g_test_watcher_add_pid (GPid pid)
 {
-  static gsize started = 0;
+  static gintptr started = 0;
   HANDLE job;
 
   if (g_once_init_enter (&started))
@@ -237,7 +237,7 @@
 static GIOChannel *
 watcher_init (void)
 {
-  static gsize started = 0;
+  static gintptr started = 0;
   static GIOChannel *channel = NULL;
   int errsv;
 
