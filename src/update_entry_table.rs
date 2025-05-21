use glib::object::{Cast, IsA, ObjectExt};
use gtk::{prelude::{ListItemExt, WidgetExt}, subclass::prelude::SelectionModelImpl, ColumnView, ColumnViewColumn, Label, ListItem, SelectionModel, SignalListItemFactory};
use crate::update_entry::UpdateEntry;

fn create_repo_factory() -> SignalListItemFactory {
    let repo_factory = SignalListItemFactory::new();
    repo_factory.connect_setup(|_, list_item| {
        let label = Label::new(None);
        label.set_hexpand(true);
        label.set_vexpand(true);
        let item = list_item.downcast_ref::<ListItem>().unwrap();
        item.set_child(Some(&label));
    });

    repo_factory.connect_bind(|_, item| {
        let list_item = item.downcast_ref::<ListItem>().unwrap();
        let item = list_item.item().unwrap();
        let obj = item.downcast_ref::<UpdateEntry>().unwrap();
        let repo = obj.property::<String>("repo");
        list_item.child().unwrap().downcast_ref::<Label>().unwrap().set_text(&repo);
    });
    repo_factory
}

fn create_name_factory() -> SignalListItemFactory {

    let name_factory = SignalListItemFactory::new();
    name_factory.connect_setup(|_, list_item| {
        let label = Label::new(None);
        label.set_hexpand(true);
        label.set_vexpand(true);
        let item = list_item.downcast_ref::<ListItem>().unwrap();
        item.set_child(Some(&label));
    });

    name_factory.connect_bind(|_, item| {
        let list_item = item.downcast_ref::<ListItem>().unwrap();
        let item = list_item.item().unwrap();
        let obj = item.downcast_ref::<UpdateEntry>().unwrap();
        let name = obj.property::<String>("name");
        list_item.child().unwrap().downcast_ref::<Label>().unwrap().set_text(&name);
    });
    name_factory
}

fn create_pre_version_factory() -> SignalListItemFactory {

    let pre_version_factory = SignalListItemFactory::new();
    pre_version_factory.connect_setup(|_, list_item| {
        let label = Label::new(None);
        label.set_hexpand(true);
        label.set_vexpand(true);
        let item = list_item.downcast_ref::<ListItem>().unwrap();
        item.set_child(Some(&label));
    });

    pre_version_factory.connect_bind(|_, item| {
        let list_item = item.downcast_ref::<ListItem>().unwrap();
        let item = list_item.item().unwrap();
        let obj = item.downcast_ref::<UpdateEntry>().unwrap();
        let pre_version = obj.property::<String>("pre-version");
        list_item.child().unwrap().downcast_ref::<Label>().unwrap().set_text(&pre_version);
    });
    pre_version_factory
}

fn create_post_version_factory() -> SignalListItemFactory {

    let post_version_factory = SignalListItemFactory::new();
    post_version_factory.connect_setup(|_, list_item| {
        let label = Label::new(None);
        label.set_hexpand(true);
        label.set_vexpand(true);
        let item = list_item.downcast_ref::<ListItem>().unwrap();
        item.set_child(Some(&label));
    });

    post_version_factory.connect_bind(|_, item| {
        let list_item = item.downcast_ref::<ListItem>().unwrap();
        let item = list_item.item().unwrap();
        let obj = item.downcast_ref::<UpdateEntry>().unwrap();
        let post_version = obj.property::<String>("post-version");
        list_item.child().unwrap().downcast_ref::<Label>().unwrap().set_text(&post_version);
    });
    post_version_factory
}

fn create_arch_factory() -> SignalListItemFactory {

    let arch_factory = SignalListItemFactory::new();
    arch_factory.connect_setup(|_, list_item| {
        let label = Label::new(None);
        label.set_hexpand(true);
        label.set_vexpand(true);
        let item = list_item.downcast_ref::<ListItem>().unwrap();
        item.set_child(Some(&label));
    });

    arch_factory.connect_bind(|_, item| {
        let list_item = item.downcast_ref::<ListItem>().unwrap();
        let item = list_item.item().unwrap();
        let obj = item.downcast_ref::<UpdateEntry>().unwrap();
        let arch = obj.property::<String>("arch");
        list_item.child().unwrap().downcast_ref::<Label>().unwrap().set_text(&arch);
    });
    arch_factory
}

fn create_repo_column() -> ColumnViewColumn {
    let column = ColumnViewColumn::new(Some("Repo"), Some(create_repo_factory()));
    column.set_expand(true);
    column
}

fn create_name_column() -> ColumnViewColumn {
    let column = ColumnViewColumn::new(Some("Name"), Some(create_name_factory()));
    column.set_expand(true);
    column
}

fn create_pre_version_column() -> ColumnViewColumn {
    let column = ColumnViewColumn::new(Some("PreVersion"), Some(create_pre_version_factory()));
    column.set_expand(true);
    column
}

fn create_post_version_column() -> ColumnViewColumn {
    let column = ColumnViewColumn::new(Some("PostVersion"), Some(create_post_version_factory()));
    column.set_expand(true);
    column
}

fn create_arch_column() -> ColumnViewColumn {
    let column = ColumnViewColumn::new(Some("Arch"), Some(create_arch_factory()));
    column.set_expand(true);
    column

}

pub fn create_update_table_view<T: IsA<SelectionModel>>(selection_model: T) -> ColumnView {
    let column_view = ColumnView::new(Some(selection_model));
    column_view.set_hexpand(true);
    column_view.set_vexpand(true);
    column_view.append_column(&create_repo_column());
    column_view.append_column(&create_name_column());
    column_view.append_column(&create_pre_version_column());
    column_view.append_column(&create_post_version_column());
    column_view.append_column(&create_arch_column());
    column_view
}
