--- gio/gdbusprivate.c.orig	2022-11-23 15:43:18.010593000 +0000
+++ gio/gdbusprivate.c	2022-11-23 15:43:39.573041000 +0000
@@ -292,7 +292,7 @@
 static SharedThreadData *
 _g_dbus_shared_thread_ref (void)
 {
-  static gsize shared_thread_data = 0;
+  static gintptr shared_thread_data = 0;
   SharedThreadData *ret;
 
   if (g_once_init_enter (&shared_thread_data))
@@ -1943,7 +1943,7 @@
 void
 _g_dbus_initialize (void)
 {
-  static gsize initialized = 0;
+  static gintptr initialized = 0;
 
   if (g_once_init_enter (&initialized))
     {
