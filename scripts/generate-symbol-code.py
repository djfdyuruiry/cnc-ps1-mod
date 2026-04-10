#!/usr/bin/env python3
"""
Python script to transform Lua type documentation JSON file 
and render the Jinja template for Lua API reference.
"""

import os
import yaml

from jinja2 import Template

def render_symbols_template(template_path: str, code_map: dict):
  print(f"Rendering jinja template file: {template_path}")

  if not os.path.exists(template_path):
    raise FileNotFoundError(f"Markdown template file not found @ {template_path}")

  with open(template_path, 'r') as f:
      template_content = f.read()

  template = Template(template_content)
  rendered = template.render(code_map=code_map, )

  return rendered

def main():
  root_dir = os.path.abspath(
    os.path.join(
        os.path.dirname(os.path.abspath(__file__)),
        ".."
    )
  )
  
  # load code map
  code_map_path = os.path.join(root_dir, 'gdi-code-map.yml')
  with open(code_map_path, 'r') as f:
    code_map = yaml.load(f, Loader=yaml.CLoader)

  # render markdown templates
  output_path = os.path.join(root_dir, 'symbols/DEFAULT.txt')
  template_path = f"{output_path}.j2"
  
  rendered_content = render_symbols_template(template_path, code_map)

  print(f"Writing rendered template to file: {output_path}")

  with open(output_path, 'w') as f:
      f.write(rendered_content)

  output_path = os.path.join(root_dir, 'include/symbols.h')
  template_path = f"{output_path}.j2"
  
  rendered_content = render_symbols_template(template_path, code_map)

  print(f"Writing rendered template to file: {output_path}")

  with open(output_path, 'w') as f:
      f.write(rendered_content)

if __name__ == '__main__':
    main()
