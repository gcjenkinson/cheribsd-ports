--- gio/gvfs.c.orig	2022-11-23 15:12:18.370914000 +0000
+++ gio/gvfs.c	2022-11-23 15:12:44.542538000 +0000
@@ -377,7 +377,7 @@
 GVfs *
 g_vfs_get_local (void)
 {
-  static gsize vfs = 0;
+  static gintptr vfs = 0;
 
   if (g_once_init_enter (&vfs))
     g_once_init_leave (&vfs, (gsize)_g_local_vfs_new ());
