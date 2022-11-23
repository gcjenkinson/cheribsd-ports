--- gobject/gtype.c.orig	2022-11-22 20:09:53.259672000 +0000
+++ gobject//gtype.c	2022-11-22 20:10:08.849581000 +0000
@@ -517,7 +517,7 @@
   node->global_gdata = NULL;
   g_hash_table_insert (static_type_nodes_ht,
 		       (gpointer) g_quark_to_string (node->qname),
-		       (gpointer) type);
+		       (gpointer) (gintptr) type);
 
   g_atomic_int_inc ((gint *)&type_registration_serial);
 
