use std::sync::mpsc;

use gtk::{prelude::{GtkWindowExt, WidgetExt}, Application, ApplicationWindow, SingleSelection};
use gio::{ListStore};
use crate::update_entry::UpdateEntry;
use crate::update_entry_table::create_update_table_view;
use crate::zypper::Zypper;
use crate::zypper::UpdateParams;

pub fn updates_window(app: &Application) {
    let window = ApplicationWindow::builder()
    .application(app)
    .title("Updates")
    .default_width(640)
    .default_height(480)
    .build();

    let model = ListStore::new::<UpdateEntry>();
    let selection_model = SingleSelection::new(Some(model.clone()));
    let table = create_update_table_view(selection_model);

    let zy = Zypper::new();
    let (sender, reciever) = mpsc::channel::<UpdateParams>();
    zy.list_of_updates(sender);

    for (repo, name, pre_version, post_version, arch) in reciever.iter() {
        model.append(
            &UpdateEntry::new(&repo, &name, &pre_version, &post_version, &arch)
        );
    }

    window.set_child(Some(&table));
    window.set_visible(true);
}