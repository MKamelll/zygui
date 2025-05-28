#include "main_window.h"

static GtkWidget *create_task_switcher()
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_hexpand(box, TRUE);

    GMenu *menu = g_menu_new();
    g_menu_append(menu, "Patterns", NULL);
    g_menu_append(menu, "Package Classification", NULL);
    g_menu_append(menu, "Languages", NULL);
    g_menu_append(menu, "Repositories", NULL);
    g_menu_append(menu, "Services", NULL);
    g_menu_append(menu, "Search", NULL);
    g_menu_append(menu, "Installation Summary", NULL);

    GtkWidget *menu_button = gtk_menu_button_new();
    GtkWidget *label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *label_text = gtk_label_new("View");
    GtkWidget *label_icon = gtk_label_new("▼");
    gtk_box_append(GTK_BOX(label_box), label_text);
    gtk_box_append(GTK_BOX(label_box), label_icon);
    gtk_menu_button_set_child(GTK_MENU_BUTTON(menu_button), label_box);
    gtk_menu_button_set_popover(GTK_MENU_BUTTON(menu_button), gtk_popover_menu_new_from_model(G_MENU_MODEL(menu)));
    gtk_widget_set_hexpand(menu_button, TRUE);
    gtk_widget_set_hexpand(label_box, TRUE);
    gtk_widget_set_hexpand(label_icon, TRUE);
    gtk_widget_set_hexpand(label_text, TRUE);
    gtk_box_append(GTK_BOX(box), menu_button);

    
    const char *task_labels[] = {"Search", "Installation Summary", "Patterns"};
    const char *task_ids[] = {"search_tab", "installation_tab", "patterns_tab"};

    GtkWidget *stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    gtk_stack_set_transition_duration(GTK_STACK(stack), 200);
    gtk_widget_set_hexpand(stack, TRUE);

    for (int i = 0; i < 3; i++)
    {
        GtkWidget *button = gtk_button_new_with_label(task_labels[i]);
        gtk_widget_set_hexpand(button, TRUE);
        gtk_widget_set_name(button, task_ids[i]);
        gtk_box_append(GTK_BOX(box), button);
    }

    return box;
}

static GtkWidget *create_menu_bar()
{
    GtkWidget *menu_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_hexpand(menu_bar, TRUE);

    // file menu
    GtkMenuButton *file_button = GTK_MENU_BUTTON(gtk_menu_button_new());
    GtkWidget *file_label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *file_label = gtk_label_new("File");
    gtk_widget_set_hexpand(file_label, TRUE);
    GtkWidget *file_icon = gtk_label_new("▼");
    gtk_widget_set_hexpand(file_icon, TRUE);
    gtk_box_append(GTK_BOX(file_label_box), file_label);
    gtk_box_append(GTK_BOX(file_label_box), file_icon);
    gtk_menu_button_set_child(file_button, file_label_box);
    gtk_widget_set_hexpand(GTK_WIDGET(file_button), TRUE);
    gtk_widget_set_hexpand(file_label_box, TRUE);
    gtk_box_append(GTK_BOX(menu_bar), GTK_WIDGET(file_button));

    GMenu *file_menu = g_menu_new();
    g_menu_append(file_menu, "Import...", NULL);
    g_menu_append(file_menu, "Export...", NULL);
    g_menu_append(file_menu, "Exit -- Discard Changes", NULL);
    g_menu_append(file_menu, "Quit -- Save Changes", NULL);

    GtkPopoverMenu *file_popover = GTK_POPOVER_MENU(gtk_popover_menu_new_from_model(G_MENU_MODEL(file_menu)));
    gtk_menu_button_set_popover(file_button, GTK_WIDGET(file_popover));

    // package
    GtkMenuButton *package_button = GTK_MENU_BUTTON(gtk_menu_button_new());
    GtkWidget *package_label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *package_label = gtk_label_new("Package");
    gtk_widget_set_hexpand(package_label, TRUE);
    GtkWidget *package_icon = gtk_label_new("▼");
    gtk_widget_set_hexpand(package_icon, TRUE);
    gtk_box_append(GTK_BOX(package_label_box), package_label);
    gtk_box_append(GTK_BOX(package_label_box), package_icon);
    gtk_widget_set_hexpand(GTK_WIDGET(package_button), TRUE);
    gtk_widget_set_hexpand(GTK_WIDGET(package_label_box), TRUE);
    gtk_menu_button_set_child(package_button, package_label_box);
    gtk_box_append(GTK_BOX(menu_bar), GTK_WIDGET(package_button));

    GMenu *package_menu = g_menu_new();
    g_menu_append(package_menu, "Install", NULL);
    g_menu_append(package_menu, "Do Not Install", NULL);
    g_menu_append(package_menu, "Keep", NULL);
    g_menu_append(package_menu, "Delete", NULL);
    g_menu_append(package_menu, "Update", NULL);
    g_menu_append(package_menu, "Update Unconditionally", NULL);
    g_menu_append(package_menu, "Taboo -- Never Install", NULL);

    GtkPopoverMenu *package_popover = GTK_POPOVER_MENU(gtk_popover_menu_new_from_model(G_MENU_MODEL(package_menu)));
    gtk_menu_button_set_popover(package_button, GTK_WIDGET(package_popover));

    // configuration
    GtkMenuButton *configuration_button = GTK_MENU_BUTTON(gtk_menu_button_new());
    GtkWidget *configuration_label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *configuration_label = gtk_label_new("Configuration");
    gtk_widget_set_hexpand(configuration_label, TRUE);
    GtkWidget *configuration_icon = gtk_label_new("▼");
    gtk_widget_set_hexpand(configuration_icon, TRUE);
    gtk_box_append(GTK_BOX(configuration_label_box), configuration_label);
    gtk_box_append(GTK_BOX(configuration_label_box), configuration_icon);
    gtk_widget_set_hexpand(GTK_WIDGET(configuration_button), TRUE);
    gtk_widget_set_hexpand(GTK_WIDGET(configuration_label_box), TRUE);
    gtk_menu_button_set_child(configuration_button, configuration_label_box);
    gtk_box_append(GTK_BOX(menu_bar), GTK_WIDGET(configuration_button));

    GMenu *configuration_menu = g_menu_new();
    g_menu_append(configuration_menu, "Repositories...", NULL);
    g_menu_append(configuration_menu, "Online Update...", NULL);

    GtkPopoverMenu *configuration_popover = GTK_POPOVER_MENU(gtk_popover_menu_new_from_model(G_MENU_MODEL(configuration_menu)));
    gtk_menu_button_set_popover(configuration_button, GTK_WIDGET(configuration_popover));

    // dependencies
    GtkMenuButton *dependencies_button = GTK_MENU_BUTTON(gtk_menu_button_new());
    GtkWidget *dependencies_label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *dependencies_label = gtk_label_new("Dependencies");
    gtk_widget_set_hexpand(dependencies_label, TRUE);
    GtkWidget *dependencies_icon = gtk_label_new("▼");
    gtk_widget_set_hexpand(dependencies_icon, TRUE);
    gtk_box_append(GTK_BOX(dependencies_label_box), dependencies_label);
    gtk_box_append(GTK_BOX(dependencies_label_box), dependencies_icon);
    gtk_widget_set_hexpand(GTK_WIDGET(dependencies_button), TRUE);
    gtk_widget_set_hexpand(GTK_WIDGET(dependencies_label_box), TRUE);
    gtk_menu_button_set_child(dependencies_button, dependencies_label_box);
    gtk_box_append(GTK_BOX(menu_bar), GTK_WIDGET(dependencies_button));

    GMenu *dependencies_menu = g_menu_new();
    g_menu_append(dependencies_menu, "Check Now", NULL);
    g_menu_append(dependencies_menu, "AutoCheck", NULL);
    g_menu_append(dependencies_menu, "Install Recommended Packages", NULL);

    GtkPopoverMenu *dependencies_popover = GTK_POPOVER_MENU(gtk_popover_menu_new_from_model(G_MENU_MODEL(dependencies_menu)));
    gtk_menu_button_set_popover(dependencies_button, GTK_WIDGET(dependencies_popover));

    // options
    GtkMenuButton *options_button = GTK_MENU_BUTTON(gtk_menu_button_new());
    GtkWidget *options_label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *options_label = gtk_label_new("Options");
    gtk_widget_set_hexpand(options_label, TRUE);
    GtkWidget *options_icon = gtk_label_new("▼");
    gtk_widget_set_hexpand(options_icon, TRUE);
    gtk_box_append(GTK_BOX(options_label_box), options_label);
    gtk_box_append(GTK_BOX(options_label_box), options_icon);
    gtk_widget_set_hexpand(GTK_WIDGET(options_button), TRUE);
    gtk_widget_set_hexpand(GTK_WIDGET(options_label_box), TRUE);
    gtk_menu_button_set_child(options_button, options_label_box);
    gtk_box_append(GTK_BOX(menu_bar), GTK_WIDGET(options_button));

    GMenu *options_menu = g_menu_new();
    g_menu_append(options_menu, "Show -devel Packages", NULL);
    g_menu_append(options_menu, "Show -debuginfo/-debugsource Packages", NULL);
    g_menu_append(options_menu, "System Verification Mode", NULL);
    g_menu_append(options_menu, "Clean Up When Deleting Packages", NULL);
    g_menu_append(options_menu, "Allow Vendor Change", NULL);

    GtkPopoverMenu *options_popover = GTK_POPOVER_MENU(gtk_popover_menu_new_from_model(G_MENU_MODEL(options_menu)));
    gtk_menu_button_set_popover(options_button, GTK_WIDGET(options_popover));

    // extras
    GtkMenuButton *extras_button = GTK_MENU_BUTTON(gtk_menu_button_new());
    GtkWidget *extras_label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *extras_label = gtk_label_new("Extras");
    gtk_widget_set_hexpand(extras_label, TRUE);
    GtkWidget *extras_icon = gtk_label_new("▼");
    gtk_widget_set_hexpand(extras_icon, TRUE);
    gtk_box_append(GTK_BOX(extras_label_box), extras_label);
    gtk_box_append(GTK_BOX(extras_label_box), extras_icon);
    gtk_widget_set_hexpand(GTK_WIDGET(extras_button), TRUE);
    gtk_widget_set_hexpand(GTK_WIDGET(extras_label_box), TRUE);
    gtk_menu_button_set_child(extras_button, extras_label_box);
    gtk_box_append(GTK_BOX(menu_bar), GTK_WIDGET(extras_button));

    GMenu *extras_menu = g_menu_new();
    g_menu_append(extras_menu, "Show Products", NULL);
    g_menu_append(extras_menu, "Show Package Changes", NULL);
    g_menu_append(extras_menu, "Show History", NULL);
    g_menu_append(extras_menu, "Install All Matching -debuginfo Packages", NULL);
    g_menu_append(extras_menu, "Install All Matching -debugsource Packages", NULL);
    g_menu_append(extras_menu, "Install All Matching Recommended Packages", NULL);
    g_menu_append(extras_menu, "Generate Dependency Resolver Test Case", NULL);
    g_menu_append(extras_menu, "Reset Ignored Dependency Conflicts", NULL);

    GtkPopoverMenu *extras_popover = GTK_POPOVER_MENU(gtk_popover_menu_new_from_model(G_MENU_MODEL(extras_menu)));
    gtk_menu_button_set_popover(extras_button, GTK_WIDGET(extras_popover));

    // help
    GtkMenuButton *help_button = GTK_MENU_BUTTON(gtk_menu_button_new());
    GtkWidget *help_label_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    GtkWidget *help_label = gtk_label_new("Help");
    gtk_widget_set_hexpand(help_label, TRUE);
    GtkWidget *help_icon = gtk_label_new("▼");
    gtk_widget_set_hexpand(help_icon, TRUE);
    gtk_box_append(GTK_BOX(help_label_box), help_label);
    gtk_box_append(GTK_BOX(help_label_box), help_icon);
    gtk_widget_set_hexpand(GTK_WIDGET(help_button), TRUE);
    gtk_widget_set_hexpand(GTK_WIDGET(help_label_box), TRUE);
    gtk_menu_button_set_child(help_button, help_label_box);
    gtk_box_append(GTK_BOX(menu_bar), GTK_WIDGET(help_button));

    GMenu *help_menu = g_menu_new();
    g_menu_append(help_menu, "Overview", NULL);
    g_menu_append(help_menu, "Symbols", NULL);
    g_menu_append(help_menu, "Keys", NULL);

    GtkPopoverMenu *help_popover = GTK_POPOVER_MENU(gtk_popover_menu_new_from_model(G_MENU_MODEL(help_menu)));
    gtk_menu_button_set_popover(help_button, GTK_WIDGET(help_popover));

    return menu_bar;

}

static GtkWidget *create_search_in_section()
{
    GtkWidget *section = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_widget_set_hexpand(section, TRUE);

    GtkWidget *search_bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    gtk_widget_set_hexpand(search_bar, TRUE);

    GtkWidget *entry_box = gtk_entry_new();
    gtk_widget_set_hexpand(entry_box, TRUE);
    gtk_box_append(GTK_BOX(search_bar), entry_box);

    GtkWidget *search_button = gtk_button_new_with_label("Search");
    gtk_widget_set_hexpand(search_button, TRUE);
    gtk_box_append(GTK_BOX(search_bar), search_button);

    gtk_box_append(GTK_BOX(section), search_bar);

    GtkWidget *search_in_label = gtk_label_new("Search in");
    gtk_widget_set_hexpand(search_in_label, TRUE);
    gtk_box_append(GTK_BOX(section), search_in_label);

    GtkWidget *name_check_box = gtk_check_button_new_with_label("Name");
    gtk_check_button_set_active(GTK_CHECK_BUTTON(name_check_box), TRUE);
    gtk_widget_set_hexpand(name_check_box, TRUE);
    
    GtkWidget *keywords_check_box = gtk_check_button_new_with_label("Keywords");
    gtk_check_button_set_active(GTK_CHECK_BUTTON(keywords_check_box), TRUE);
    gtk_widget_set_hexpand(keywords_check_box, TRUE);
    
    GtkWidget *summary_check_box = gtk_check_button_new_with_label("Summary");
    gtk_check_button_set_active(GTK_CHECK_BUTTON(summary_check_box), TRUE);
    gtk_widget_set_hexpand(summary_check_box, TRUE);
    
    GtkWidget *description_check_box = gtk_check_button_new_with_label("Description");
    gtk_widget_set_hexpand(description_check_box, TRUE);
    
    GtkWidget *rpm_provides_check_box = gtk_check_button_new_with_label("RPM \"Provides\"");
    gtk_widget_set_hexpand(rpm_provides_check_box, TRUE);

    GtkWidget *rpm_requires_check_box = gtk_check_button_new_with_label("RPM \"Requires\"");
    gtk_widget_set_hexpand(rpm_requires_check_box, TRUE);

    GtkWidget *file_list_check_box = gtk_check_button_new_with_label("File List");
    gtk_widget_set_hexpand(file_list_check_box, TRUE);

    gtk_box_append(GTK_BOX(section), name_check_box);
    gtk_box_append(GTK_BOX(section), keywords_check_box);
    gtk_box_append(GTK_BOX(section), summary_check_box);
    gtk_box_append(GTK_BOX(section), description_check_box);
    gtk_box_append(GTK_BOX(section), rpm_provides_check_box);
    gtk_box_append(GTK_BOX(section), rpm_requires_check_box);
    gtk_box_append(GTK_BOX(section), file_list_check_box);

    GtkStringList *dropdown_options = gtk_string_list_new((const char *[]) {
        "Contains",
        "Begins With",
        "Exact Match",
        "Use Wild Cards",
        "Use Regular Expression",
        NULL
    });

    GtkWidget *drop_down = gtk_drop_down_new(G_LIST_MODEL(dropdown_options), NULL);
    gtk_drop_down_set_selected(GTK_DROP_DOWN(drop_down), 0);

    gtk_box_append(GTK_BOX(section), drop_down);

    GtkWidget *case_sensitive_check_box = gtk_check_button_new_with_label("Case Sensitive");
    gtk_widget_set_hexpand(case_sensitive_check_box, TRUE);

    gtk_box_append(GTK_BOX(section), case_sensitive_check_box);

    return section;
}

static void on_setup_list_item(GtkListItemFactory *factory, GtkListItem *item, gpointer user_data)
{
    GtkWidget *label = gtk_label_new(NULL);
    gtk_widget_set_hexpand(label, TRUE);
    gtk_list_item_set_child(item, label);
    g_object_bind_property(gtk_list_item_get_item(item), "string", label, "label", G_BINDING_SYNC_CREATE);
}

static GtkWidget *create_package_details_table(GtkStringList *package_table_header_items)
{
    GtkSingleSelection *sel = gtk_single_selection_new(G_LIST_MODEL(package_table_header_items));
    
    GtkListItemFactory *factory = gtk_signal_list_item_factory_new();
    g_signal_connect(factory, "setup", G_CALLBACK(on_setup_list_item), NULL);

    GtkColumnViewColumn *package_column = gtk_column_view_column_new("Package", factory);
    gtk_column_view_column_set_expand(package_column, TRUE);

    GtkColumnViewColumn *summary_column = gtk_column_view_column_new("Summary", factory);
    gtk_column_view_column_set_expand(summary_column, TRUE);

    GtkColumnViewColumn *installed_column = gtk_column_view_column_new("Installed(Available)", factory);
    gtk_column_view_column_set_expand(installed_column, TRUE);

    GtkColumnViewColumn *size_column = gtk_column_view_column_new("Size", factory);
    gtk_column_view_column_set_expand(size_column, TRUE);

    GtkWidget *column_view = gtk_column_view_new(GTK_SELECTION_MODEL(sel));
    gtk_widget_set_hexpand(column_view, TRUE);
    gtk_widget_set_vexpand(column_view, TRUE);
    gtk_column_view_append_column(GTK_COLUMN_VIEW(column_view), package_column);
    gtk_column_view_append_column(GTK_COLUMN_VIEW(column_view), summary_column);
    gtk_column_view_append_column(GTK_COLUMN_VIEW(column_view), installed_column);
    gtk_column_view_append_column(GTK_COLUMN_VIEW(column_view), size_column);

    return column_view;
}

static GtkWidget *create_package_details_section()
{
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_hexpand(box, TRUE);
    gtk_widget_set_vexpand(box, TRUE);

    GtkStringList *package_table_rows = gtk_string_list_new((const char *[]){
        NULL
    });

    GtkWidget *package_details_table = create_package_details_table(package_table_rows);
    
    gtk_box_append(GTK_BOX(box), package_details_table);
    return box;
}

GtkWidget *create_main_window(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Zygui");
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_window_set_child(GTK_WINDOW(window), box);
    gtk_widget_set_hexpand(box, TRUE);

    GtkWidget *menu_bar = create_menu_bar();
    gtk_box_append(GTK_BOX(box), menu_bar);

    GtkWidget *stack = create_task_switcher();
    gtk_box_append(GTK_BOX(box), stack);

    GtkWidget *search_in_section = create_search_in_section();    
    GtkWidget *package_details_section = create_package_details_section();

    GtkWidget *paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_paned_set_start_child(GTK_PANED(paned), search_in_section);
    gtk_paned_set_end_child(GTK_PANED(paned), package_details_section);

    gtk_box_append(GTK_BOX(box), paned);

    return window;
}