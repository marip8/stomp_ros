/**
 * @file constraint_group.h
 * @brief Base class for IK-solver Constraints
 * Specify relationship between joint velocities and constraint "error"
 * @author dsolomon
 * @date Sep 15, 2013
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2013, Southwest Research Institute
 *
 * @license Software License Agreement (Apache License)\n
 * \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at\n
 * \n
 * http://www.apache.org/licenses/LICENSE-2.0\n
 * \n
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef CONSTRAINT_GROUP_H
#define CONSTRAINT_GROUP_H

#include "constraint.h"
#include <boost/ptr_container/ptr_vector.hpp>

namespace constrained_ik
{

/**
 * @brief Group of constraints for use in iterative constrained_IK solver
 */
class ConstraintGroup : public Constraint
{
public:
  ConstraintGroup();
  virtual ~ConstraintGroup() {}

  virtual Eigen::MatrixXd calcJacobian();
  virtual Eigen::VectorXd calcError();

  virtual void init(const Constrained_IK* ik);
  virtual void reset();
  virtual void update(const SolverState &state);
  virtual bool checkStatus() const;

  virtual void add(Constraint* constraint);
  virtual void clear() { constraints_.clear(); }
  bool empty() const { return constraints_.empty(); }
  bool collision_checks_required();

protected:
  boost::ptr_vector<Constraint> constraints_;

}; // class ConstraintGroup

} // namespace constrained_ik


#endif // CONSTRAINT_GROUP_H

