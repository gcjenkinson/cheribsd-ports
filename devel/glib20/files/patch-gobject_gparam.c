--- gobject/gparam.c.orig	2022-11-22 17:58:40.055760000 +0000
+++ gobject/gparam.c	2022-11-23 09:55:17.056017000 +0000
@@ -1183,7 +1183,7 @@
   
   g_mutex_lock (&pool->mutex);
   data[0] = NULL;
-  data[1] = (gpointer) owner_type;
+  data[1] = (gpointer) (gintptr) owner_type;
   g_hash_table_foreach (pool->hash_table, pool_list, &data);
   g_mutex_unlock (&pool->mutex);
 
@@ -1322,7 +1322,7 @@
   d = g_type_depth (owner_type);
   slists = g_new0 (GSList*, d);
   data[0] = slists;
-  data[1] = (gpointer) owner_type;
+  data[1] = (gpointer) (gintptr) owner_type;
   data[2] = pool->hash_table;
   data[3] = &n_pspecs;
 
