/* Copyright JS Foundation and other contributors, http://js.foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "jerryscript.h"
#include "test-common.h"

int
main (void)
{
  TEST_INIT ();

  jerry_init (JERRY_INIT_EMPTY);

  jerry_value_t obj_val = jerry_create_object ();
  obj_val = jerry_create_error_from (obj_val, false);
  jerry_value_t err_val = jerry_acquire_value (obj_val);

  obj_val = jerry_get_value_from_error (obj_val, true);

  JERRY_ASSERT (obj_val != err_val);
  jerry_release_value (err_val);
  jerry_release_value (obj_val);

  jerry_value_t value = jerry_create_number (42);
  jerry_value_t abort = jerry_create_abort_from_value (value, true);
  abort = jerry_create_abort_from_value (abort, true);
  jerry_release_value (abort);

  value = jerry_create_number (42);
  abort = jerry_create_abort_from_value (value, true);
  jerry_value_t abort2 = jerry_create_abort_from_value (abort, false);
  jerry_release_value (abort);
  jerry_release_value (abort2);

  jerry_cleanup ();
} /* main */
