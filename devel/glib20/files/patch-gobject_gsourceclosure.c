37c37
<   if (g_once_init_enter (&etype))
---
>   if (g_once_init_enter ((gintptr) etype))
49c49
<       g_once_init_leave (&etype, type_id);
---
>       g_once_init_leave (&etype, (gintptr) type_id);
