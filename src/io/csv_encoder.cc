/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "singa/io/encoder.h"
#include <sstream>

namespace singa {

std::string CSVEncoder::Encode(vector<Tensor>& data) {
  CHECK_GE(data.size(), 1u);
  size_t size = data[0].Size();
  const float* value = data[0].data<float>();
  std::string des = "";
  if (data.size() == 2) {
    const float label = (const float)data[1].data<int>()[0];
    std::ostringstream buff;
    buff << label;
    des += buff.str() + ',';
  }
  for (size_t i = 0; i < size; i++) {
    std::ostringstream buff;
    buff << value[i];
    if (i == size - 1) des += buff.str();
    else des += buff.str() + ',';
  }
  return des;
}
}  // namespace singa
