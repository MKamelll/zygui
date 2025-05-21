use glib::subclass::prelude::*;
use glib::subclass::types::FromObject;
use glib::{Object};

mod imp;

glib::wrapper! {
    pub struct UpdateEntry(ObjectSubclass<imp::UpdateEntry>);
}

impl UpdateEntry {
    pub fn new(
        repo: &str,
        name: &str,
        pre_version: &str,
        post_version: &str,
        arch: &str
    ) -> Self {
        Object::builder()
        .property("repo", repo.to_string())
        .property("name", name.to_string())
        .property("pre-version", pre_version.to_string())
        .property("post-version", post_version.to_string())
        .property("arch", arch.to_string())
        .build()
    }

    pub fn repo(&self) -> String {
        let imp = imp::UpdateEntry::from_object(self);
        imp.repo.borrow_mut().clone()
    }


    pub fn name(&self) -> String {
        let imp = imp::UpdateEntry::from_object(self);
        imp.name.borrow_mut().clone()
    }


    pub fn pre_version(&self) -> String {
        let imp = imp::UpdateEntry::from_object(self);
        imp.pre_version.borrow_mut().clone()
    }


    pub fn post_version(&self) -> String {
        let imp = imp::UpdateEntry::from_object(self);
        imp.post_version.borrow_mut().clone()
    }


    pub fn arch(&self) -> String {
        let imp = imp::UpdateEntry::from_object(self);
        imp.arch.borrow_mut().clone()
    }
}