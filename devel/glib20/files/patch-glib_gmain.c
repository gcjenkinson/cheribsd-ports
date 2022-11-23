--- glib/gmain.c.orig	2022-11-22 11:20:54.303288000 +0000
+++ glib/gmain.c	2022-11-22 17:22:03.944264000 +0000
@@ -690,7 +690,7 @@
 GMainContext *
 g_main_context_new_with_flags (GMainContextFlags flags)
 {
-  static gsize initialised;
+  static gintptr initialised;
   GMainContext *context;
 
   if (g_once_init_enter (&initialised))
@@ -6189,7 +6189,7 @@
 GMainContext *
 g_get_worker_context (void)
 {
-  static gsize initialised;
+  static gintptr initialised;
 
   if (g_once_init_enter (&initialised))
     {
