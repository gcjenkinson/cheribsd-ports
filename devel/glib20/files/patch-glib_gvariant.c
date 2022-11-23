--- glib/gvariant.c.orig	2022-11-22 12:42:08.518758000 +0000
+++ glib/gvariant.c	2022-11-22 12:54:47.442607000 +0000
@@ -3201,7 +3201,7 @@
 
 /* Just to make sure that by adding a union to GVariantBuilder, we
  * didn't accidentally change ABI. */
-G_STATIC_ASSERT (sizeof (GVariantBuilder) == sizeof (gsize[16]));
+G_STATIC_ASSERT (sizeof (GVariantBuilder) == sizeof (gsize[16]) + sizeof(gintptr));
 
 static gboolean
 ensure_valid_builder (GVariantBuilder *builder)
@@ -3877,7 +3877,7 @@
 
 /* Just to make sure that by adding a union to GVariantDict, we didn't
  * accidentally change ABI. */
-G_STATIC_ASSERT (sizeof (GVariantDict) == sizeof (gsize[16]));
+G_STATIC_ASSERT (sizeof (GVariantDict) == sizeof (gsize[18]));
 
 static gboolean
 ensure_valid_dict (GVariantDict *dict)
