--- gio/glocalfile.c.orig	2022-11-23 15:56:23.739500000 +0000
+++ gio/glocalfile.c	2022-11-23 16:01:02.266631000 +0000
@@ -96,7 +96,7 @@
 static void g_local_file_file_iface_init (GFileIface *iface);
 
 static GFileAttributeInfoList *local_writable_attributes = NULL;
-static /* GFileAttributeInfoList * */ gsize local_writable_namespaces = 0;
+static /* GFileAttributeInfoList * */ gintptr local_writable_namespaces = 0;
 
 struct _GLocalFile
 {
@@ -1824,7 +1824,7 @@
 gboolean
 _g_local_file_has_trash_dir (const char *dirname, dev_t dir_dev)
 {
-  static gsize home_dev_set = 0;
+  static gintptr home_dev_set = 0;
   static dev_t home_dev;
   static gboolean home_dev_valid = FALSE;
   char *topdir, *globaldir, *trashdir, *tmpname;
@@ -2598,7 +2598,7 @@
 g_local_file_is_nfs_home (const gchar *filename)
 {
   static gboolean remote_home = FALSE;
-  static gsize initialized;
+  static gintptr initialized;
   const gchar *home;
 
   home = g_get_home_dir ();
