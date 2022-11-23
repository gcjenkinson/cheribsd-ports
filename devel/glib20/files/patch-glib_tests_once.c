--- glib/tests/once.c.orig	2022-11-22 12:59:09.664321000 +0000
+++ glib/tests/once.c	2022-11-22 13:00:10.820042000 +0000
@@ -128,7 +128,7 @@
 static void
 test_once_init_single_threaded (void)
 {
-  static gsize init = 0;
+  static gintptr init = 0;
 
   g_test_summary ("Test g_once_init_{enter,leave}() usage from a single thread");
 
@@ -152,7 +152,7 @@
 static void
 init_shared (void)
 {
-  static gsize init = 0;
+  static gintptr init = 0;
 
   if (g_once_init_enter (&init))
     {
