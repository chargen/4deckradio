#ifndef _AUDIO_H
#define _AUDIO_H

int init_audio(CustomData *data, guint decknumber, int autoconnect);
void audio_set_uri(CustomData *data, const gchar *uri);
GstStateChangeReturn audio_stop_player (CustomData *data);
GstStateChangeReturn audio_pause_player (CustomData *data);

#endif /* _AUDIO_H */