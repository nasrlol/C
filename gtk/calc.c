#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

GtkWidget *entry1, *entry2, *result_label;

void add_numbers(GtkWidget *widget, gpointer data) {
    const char *num1 = gtk_entry_get_text(GTK_ENTRY(entry1));
    const char *num2 = gtk_entry_get_text(GTK_ENTRY(entry2));
    
    double n1 = atof(num1);
    double n2 = atof(num2);
    double sum = n1 + n2;

    char result[50];
    snprintf(result, 50, "Result: %.2f", sum);
    gtk_label_set_text(GTK_LABEL(result_label), result);
}

void destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window, *grid, *add_button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    entry1 = gtk_entry_new();
    entry2 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Number 1:"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry1, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Number 2:"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry2, 1, 1, 1, 1);

    
    add_button = gtk_button_new_with_label("+");
    gtk_grid_attach(GTK_GRID(grid), add_button, 0, 2, 2, 1);
    g_signal_connect(add_button, "clicked", G_CALLBACK(add_numbers), NULL);

    result_label = gtk_label_new("Result: ");
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 3, 2, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}