// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef PROTOBUF_message_2eproto__INCLUDED
#define PROTOBUF_message_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_message_2eproto();
void protobuf_AssignDesc_message_2eproto();
void protobuf_ShutdownFile_message_2eproto();

class Login;
class Register;
class Status;

// ===================================================================

class Login : public ::google::protobuf::Message {
 public:
  Login();
  virtual ~Login();

  Login(const Login& from);

  inline Login& operator=(const Login& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Login& default_instance();

  void Swap(Login* other);

  // implements Message ----------------------------------------------

  Login* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Login& from);
  void MergeFrom(const Login& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string user_name = 1;
  inline bool has_user_name() const;
  inline void clear_user_name();
  static const int kUserNameFieldNumber = 1;
  inline const ::std::string& user_name() const;
  inline void set_user_name(const ::std::string& value);
  inline void set_user_name(const char* value);
  inline void set_user_name(const char* value, size_t size);
  inline ::std::string* mutable_user_name();
  inline ::std::string* release_user_name();
  inline void set_allocated_user_name(::std::string* user_name);

  // optional string password = 2;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 2;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:Login)
 private:
  inline void set_has_user_name();
  inline void clear_has_user_name();
  inline void set_has_password();
  inline void clear_has_password();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* user_name_;
  ::std::string* password_;
  friend void  protobuf_AddDesc_message_2eproto();
  friend void protobuf_AssignDesc_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

  void InitAsDefaultInstance();
  static Login* default_instance_;
};
// -------------------------------------------------------------------

class Register : public ::google::protobuf::Message {
 public:
  Register();
  virtual ~Register();

  Register(const Register& from);

  inline Register& operator=(const Register& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Register& default_instance();

  void Swap(Register* other);

  // implements Message ----------------------------------------------

  Register* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Register& from);
  void MergeFrom(const Register& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string user_name = 1;
  inline bool has_user_name() const;
  inline void clear_user_name();
  static const int kUserNameFieldNumber = 1;
  inline const ::std::string& user_name() const;
  inline void set_user_name(const ::std::string& value);
  inline void set_user_name(const char* value);
  inline void set_user_name(const char* value, size_t size);
  inline ::std::string* mutable_user_name();
  inline ::std::string* release_user_name();
  inline void set_allocated_user_name(::std::string* user_name);

  // optional string password1 = 2;
  inline bool has_password1() const;
  inline void clear_password1();
  static const int kPassword1FieldNumber = 2;
  inline const ::std::string& password1() const;
  inline void set_password1(const ::std::string& value);
  inline void set_password1(const char* value);
  inline void set_password1(const char* value, size_t size);
  inline ::std::string* mutable_password1();
  inline ::std::string* release_password1();
  inline void set_allocated_password1(::std::string* password1);

  // optional string password2 = 3;
  inline bool has_password2() const;
  inline void clear_password2();
  static const int kPassword2FieldNumber = 3;
  inline const ::std::string& password2() const;
  inline void set_password2(const ::std::string& value);
  inline void set_password2(const char* value);
  inline void set_password2(const char* value, size_t size);
  inline ::std::string* mutable_password2();
  inline ::std::string* release_password2();
  inline void set_allocated_password2(::std::string* password2);

  // @@protoc_insertion_point(class_scope:Register)
 private:
  inline void set_has_user_name();
  inline void clear_has_user_name();
  inline void set_has_password1();
  inline void clear_has_password1();
  inline void set_has_password2();
  inline void clear_has_password2();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* user_name_;
  ::std::string* password1_;
  ::std::string* password2_;
  friend void  protobuf_AddDesc_message_2eproto();
  friend void protobuf_AssignDesc_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

  void InitAsDefaultInstance();
  static Register* default_instance_;
};
// -------------------------------------------------------------------

class Status : public ::google::protobuf::Message {
 public:
  Status();
  virtual ~Status();

  Status(const Status& from);

  inline Status& operator=(const Status& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Status& default_instance();

  void Swap(Status* other);

  // implements Message ----------------------------------------------

  Status* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Status& from);
  void MergeFrom(const Status& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 register = 1;
  inline bool has_register_() const;
  inline void clear_register_();
  static const int kRegisterFieldNumber = 1;
  inline ::google::protobuf::int32 register_() const;
  inline void set_register_(::google::protobuf::int32 value);

  // optional int32 login = 2;
  inline bool has_login() const;
  inline void clear_login();
  static const int kLoginFieldNumber = 2;
  inline ::google::protobuf::int32 login() const;
  inline void set_login(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Status)
 private:
  inline void set_has_register_();
  inline void clear_has_register_();
  inline void set_has_login();
  inline void clear_has_login();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 register__;
  ::google::protobuf::int32 login_;
  friend void  protobuf_AddDesc_message_2eproto();
  friend void protobuf_AssignDesc_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

  void InitAsDefaultInstance();
  static Status* default_instance_;
};
// ===================================================================


// ===================================================================

// Login

// optional string user_name = 1;
inline bool Login::has_user_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Login::set_has_user_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Login::clear_has_user_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Login::clear_user_name() {
  if (user_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_->clear();
  }
  clear_has_user_name();
}
inline const ::std::string& Login::user_name() const {
  // @@protoc_insertion_point(field_get:Login.user_name)
  return *user_name_;
}
inline void Login::set_user_name(const ::std::string& value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
  // @@protoc_insertion_point(field_set:Login.user_name)
}
inline void Login::set_user_name(const char* value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:Login.user_name)
}
inline void Login::set_user_name(const char* value, size_t size) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Login.user_name)
}
inline ::std::string* Login::mutable_user_name() {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Login.user_name)
  return user_name_;
}
inline ::std::string* Login::release_user_name() {
  clear_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = user_name_;
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Login::set_allocated_user_name(::std::string* user_name) {
  if (user_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete user_name_;
  }
  if (user_name) {
    set_has_user_name();
    user_name_ = user_name;
  } else {
    clear_has_user_name();
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Login.user_name)
}

// optional string password = 2;
inline bool Login::has_password() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Login::set_has_password() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Login::clear_has_password() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Login::clear_password() {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& Login::password() const {
  // @@protoc_insertion_point(field_get:Login.password)
  return *password_;
}
inline void Login::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set:Login.password)
}
inline void Login::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(value);
  // @@protoc_insertion_point(field_set_char:Login.password)
}
inline void Login::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Login.password)
}
inline ::std::string* Login::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Login.password)
  return password_;
}
inline ::std::string* Login::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Login::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Login.password)
}

// -------------------------------------------------------------------

// Register

// optional string user_name = 1;
inline bool Register::has_user_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Register::set_has_user_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Register::clear_has_user_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Register::clear_user_name() {
  if (user_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_->clear();
  }
  clear_has_user_name();
}
inline const ::std::string& Register::user_name() const {
  // @@protoc_insertion_point(field_get:Register.user_name)
  return *user_name_;
}
inline void Register::set_user_name(const ::std::string& value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
  // @@protoc_insertion_point(field_set:Register.user_name)
}
inline void Register::set_user_name(const char* value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:Register.user_name)
}
inline void Register::set_user_name(const char* value, size_t size) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Register.user_name)
}
inline ::std::string* Register::mutable_user_name() {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    user_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Register.user_name)
  return user_name_;
}
inline ::std::string* Register::release_user_name() {
  clear_has_user_name();
  if (user_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = user_name_;
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Register::set_allocated_user_name(::std::string* user_name) {
  if (user_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete user_name_;
  }
  if (user_name) {
    set_has_user_name();
    user_name_ = user_name;
  } else {
    clear_has_user_name();
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Register.user_name)
}

// optional string password1 = 2;
inline bool Register::has_password1() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Register::set_has_password1() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Register::clear_has_password1() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Register::clear_password1() {
  if (password1_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password1_->clear();
  }
  clear_has_password1();
}
inline const ::std::string& Register::password1() const {
  // @@protoc_insertion_point(field_get:Register.password1)
  return *password1_;
}
inline void Register::set_password1(const ::std::string& value) {
  set_has_password1();
  if (password1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password1_ = new ::std::string;
  }
  password1_->assign(value);
  // @@protoc_insertion_point(field_set:Register.password1)
}
inline void Register::set_password1(const char* value) {
  set_has_password1();
  if (password1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password1_ = new ::std::string;
  }
  password1_->assign(value);
  // @@protoc_insertion_point(field_set_char:Register.password1)
}
inline void Register::set_password1(const char* value, size_t size) {
  set_has_password1();
  if (password1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password1_ = new ::std::string;
  }
  password1_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Register.password1)
}
inline ::std::string* Register::mutable_password1() {
  set_has_password1();
  if (password1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password1_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Register.password1)
  return password1_;
}
inline ::std::string* Register::release_password1() {
  clear_has_password1();
  if (password1_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = password1_;
    password1_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Register::set_allocated_password1(::std::string* password1) {
  if (password1_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete password1_;
  }
  if (password1) {
    set_has_password1();
    password1_ = password1;
  } else {
    clear_has_password1();
    password1_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Register.password1)
}

// optional string password2 = 3;
inline bool Register::has_password2() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Register::set_has_password2() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Register::clear_has_password2() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Register::clear_password2() {
  if (password2_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password2_->clear();
  }
  clear_has_password2();
}
inline const ::std::string& Register::password2() const {
  // @@protoc_insertion_point(field_get:Register.password2)
  return *password2_;
}
inline void Register::set_password2(const ::std::string& value) {
  set_has_password2();
  if (password2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password2_ = new ::std::string;
  }
  password2_->assign(value);
  // @@protoc_insertion_point(field_set:Register.password2)
}
inline void Register::set_password2(const char* value) {
  set_has_password2();
  if (password2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password2_ = new ::std::string;
  }
  password2_->assign(value);
  // @@protoc_insertion_point(field_set_char:Register.password2)
}
inline void Register::set_password2(const char* value, size_t size) {
  set_has_password2();
  if (password2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password2_ = new ::std::string;
  }
  password2_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Register.password2)
}
inline ::std::string* Register::mutable_password2() {
  set_has_password2();
  if (password2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    password2_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Register.password2)
  return password2_;
}
inline ::std::string* Register::release_password2() {
  clear_has_password2();
  if (password2_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = password2_;
    password2_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Register::set_allocated_password2(::std::string* password2) {
  if (password2_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete password2_;
  }
  if (password2) {
    set_has_password2();
    password2_ = password2;
  } else {
    clear_has_password2();
    password2_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Register.password2)
}

// -------------------------------------------------------------------

// Status

// optional int32 register = 1;
inline bool Status::has_register_() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Status::set_has_register_() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Status::clear_has_register_() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Status::clear_register_() {
  register__ = 0;
  clear_has_register_();
}
inline ::google::protobuf::int32 Status::register_() const {
  // @@protoc_insertion_point(field_get:Status.register)
  return register__;
}
inline void Status::set_register_(::google::protobuf::int32 value) {
  set_has_register_();
  register__ = value;
  // @@protoc_insertion_point(field_set:Status.register)
}

// optional int32 login = 2;
inline bool Status::has_login() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Status::set_has_login() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Status::clear_has_login() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Status::clear_login() {
  login_ = 0;
  clear_has_login();
}
inline ::google::protobuf::int32 Status::login() const {
  // @@protoc_insertion_point(field_get:Status.login)
  return login_;
}
inline void Status::set_login(::google::protobuf::int32 value) {
  set_has_login();
  login_ = value;
  // @@protoc_insertion_point(field_set:Status.login)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_2eproto__INCLUDED
