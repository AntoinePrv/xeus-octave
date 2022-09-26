/*
 * Copyright (C) 2020 Giulio Girardi.
 *
 * This file is part of xeus-octave.
 *
 * xeus-octave is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xeus-octave is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xeus-octave.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLOTLY_TOOLKIT_H
#define PLOTLY_TOOLKIT_H

#include <vector>

#include <octave/graphics-toolkit.h>
#include <octave/graphics.h>
#include <octave/interpreter.h>

namespace xeus_octave
{

class plotly_graphics_toolkit : public octave::base_graphics_toolkit
{
public:

  plotly_graphics_toolkit(octave::interpreter& interp);

  bool is_valid() const override { return true; }

  bool initialize(octave::graphics_object const& go) override;
  void redraw_figure(octave::graphics_object const& go) const override;
  void show_figure(octave::graphics_object const& go) const override;

private:

  /**
   * Get a vector of all the children of the @go octave::graphics_object
   */
  std::vector<octave::graphics_object>
  children(octave::graphics_object const& go, bool all = false) const;

private:

  octave::interpreter& m_interpreter;
};

}  // namespace xeus_octave

#endif
