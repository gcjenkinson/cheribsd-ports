--- gobject/gobject.c.orig	2022-11-23 10:12:34.109365000 +0000
+++ gobject/gobject.c	2022-11-23 14:24:06.108189000 +0000
@@ -3190,13 +3190,13 @@
       do
         oldvalue = g_atomic_pointer_get (&object->qdata);
       while (!g_atomic_pointer_compare_and_exchange ((void**) &object->qdata, oldvalue,
-                                                     (gpointer) ((gsize) oldvalue | OBJECT_FLOATING_FLAG)));
+                                                     (gpointer) ((gintptr) oldvalue | OBJECT_FLOATING_FLAG)));
       return (gsize) oldvalue & OBJECT_FLOATING_FLAG;
     case -1:    /* sink if possible */
       do
         oldvalue = g_atomic_pointer_get (&object->qdata);
       while (!g_atomic_pointer_compare_and_exchange ((void**) &object->qdata, oldvalue,
-                                                     (gpointer) ((gsize) oldvalue & ~(gsize) OBJECT_FLOATING_FLAG)));
+                                                     (gpointer) ((gintptr) oldvalue & ~(gintptr) OBJECT_FLOATING_FLAG)));
       return (gsize) oldvalue & OBJECT_FLOATING_FLAG;
     default:    /* check floating */
       return 0 != ((gsize) g_atomic_pointer_get (&object->qdata) & OBJECT_FLOATING_FLAG);
