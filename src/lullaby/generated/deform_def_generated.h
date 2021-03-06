// Autogenerated code.  Do not edit.
#ifndef _SRC_LULLABY_GENERATED_DEFORM_DEF_GENERATED_H_
#define _SRC_LULLABY_GENERATED_DEFORM_DEF_GENERATED_H_

#include <type_traits>
#include <memory>
#include "flatbuffers/deform_def_generated.h"
#include "lullaby/base/common_types.h"
#include "lullaby/base/typeid.h"
#include "lullaby/util/color.h"
#include "lullaby/util/math.h"
#include "lullaby/util/optional.h"
#include "common_generated.h"

namespace lull {
class DeformedDefT;
class DeformerDefT;
class WaypointPathT;
class WaypointT;
class DeformedDefT {
 public:
  using FlatBufferType = DeformedDef;

  std::string waypoint_path_id;

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

class DeformerDefT {
 public:
  using FlatBufferType = DeformerDef;

  lull::DeformMode deform_mode = lull::DeformMode_CylinderBend;
  float horizontal_radius = 0.0f;
  float clamp_angle = 0.0f;
  std::vector<lull::WaypointPathT> waypoint_paths;

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

class WaypointPathT {
 public:
  using FlatBufferType = WaypointPath;

  std::string path_id;
  std::vector<lull::WaypointT> waypoints;

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

class WaypointT {
 public:
  using FlatBufferType = Waypoint;

  mathfu::vec3 original_position = {0.f, 0.f, 0.f};
  mathfu::vec3 remapped_position = {0.f, 0.f, 0.f};
  mathfu::vec3 remapped_rotation = {0.f, 0.f, 0.f};

  template <typename Archive>
  void SerializeFlatbuffer(Archive archive);
};

template <typename Archive>
void DeformedDefT::SerializeFlatbuffer(Archive archive) {
  archive.String(&waypoint_path_id, 4);
}

template <typename Archive>
void DeformerDefT::SerializeFlatbuffer(Archive archive) {
  archive.VectorOfTables(&waypoint_paths, 10);
  int32_t _deform_mode = static_cast<int32_t>(deform_mode);
  archive.Scalar(&_deform_mode, 4, lull::DeformMode_CylinderBend);
  deform_mode = static_cast<lull::DeformMode>(_deform_mode);
  archive.Scalar(&horizontal_radius, 6, 0.0f);
  archive.Scalar(&clamp_angle, 8, 0.0f);
}

template <typename Archive>
void WaypointPathT::SerializeFlatbuffer(Archive archive) {
  archive.String(&path_id, 4);
  archive.VectorOfTables(&waypoints, 6);
}

template <typename Archive>
void WaypointT::SerializeFlatbuffer(Archive archive) {
  archive.NativeStruct(&original_position, 4);
  archive.NativeStruct(&remapped_position, 6);
  archive.NativeStruct(&remapped_rotation, 8);
}

}  // namespace lull

LULLABY_SETUP_TYPEID(lull::DeformedDefT);
LULLABY_SETUP_TYPEID(lull::DeformerDefT);
LULLABY_SETUP_TYPEID(lull::WaypointPathT);
LULLABY_SETUP_TYPEID(lull::WaypointT);

#endif  // _SRC_LULLABY_GENERATED_DEFORM_DEF_GENERATED_H_

