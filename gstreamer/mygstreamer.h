#ifndef _MYGSTREAMER_H
#define _MYGSTREAMER_H

#define HMS_TIME_FORMAT "u:%02u:%02u"

#define HMS_TIME_ARGS(t) \
        GST_CLOCK_TIME_IS_VALID (t) ? \
        (guint) (((GstClockTime)(t)) / (GST_SECOND * 60 * 60)) : 99, \
        GST_CLOCK_TIME_IS_VALID (t) ? \
        (guint) ((((GstClockTime)(t)) / (GST_SECOND * 60)) % 60) : 99, \
        GST_CLOCK_TIME_IS_VALID (t) ? \
        (guint) ((((GstClockTime)(t)) / GST_SECOND) % 60) : 99


/* Structure to contain all our information, so we can pass it around */
typedef struct _CustomData {
    GstElement *pipeline;           /* Our one and only pipeline */
    GstElement *audioconvert;
    GstElement *audioresample;
    GstElement *uridecodebin;
    GstElement *jackaudiosink;

    GtkWidget *slider;              /* Slider widget to keep track of current position */
    GtkWidget *taglabel;
    GtkWidget *timelabel;
    GtkWidget *playPauseButton;
    GtkWidget *filechooser;
    GtkWidget *mainwindow;
    gulong slider_update_signal_id; /* Signal ID for the slider update signal */

    gulong file_selection_signal_id;

    GstState state;                 /* Current state of the pipeline */
    gint64 duration;                /* Duration of the clip, in nanoseconds */
} CustomData;

#endif /* _MYGSTREAMER_H */