--- gobject/gclosure.c.orig	2022-11-23 13:01:39.895914000 +0000
+++ gobject/gclosure.c	2022-11-23 13:25:06.699288000 +0000
@@ -1171,7 +1171,7 @@
   g_return_val_if_fail (G_TYPE_IS_CLASSED (itype) || G_TYPE_IS_INTERFACE (itype), NULL);
   g_return_val_if_fail (struct_offset >= sizeof (GTypeClass), NULL);
   
-  closure = g_closure_new_simple (sizeof (GClosure), (gpointer) itype);
+  closure = g_closure_new_simple (sizeof (GClosure), (gpointer) (gintptr) itype);
   if (G_TYPE_IS_INTERFACE (itype))
     {
       g_closure_set_meta_marshal (closure, GUINT_TO_POINTER (struct_offset), g_type_iface_meta_marshal);
