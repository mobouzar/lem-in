#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    draw.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 16:09:51 by mobouzar          #+#    #+#              #
#    Updated: 2020/02/04 16:09:52 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import networkx as nx

def check_args(args, flag):
    for arg in args:
        if (arg == flag):
            return (True)
    return (False)

def check_graph_size(field, settings):
	if (len(field.nodes)) < 100:
		settings["markersize"] = 20.0
		settings["node_size"] = 500
		settings["window_size"] = (12, 8)
	elif (len(field.nodes)) < 1000:
		settings["markersize"] = 10.0
		settings["node_size"] = 300
		settings["window_size"] = (16, 12)
	elif (len(field.nodes)) > 1000:
		settings["markersize"] = 5.0
		settings["node_size"] = 100
		settings["window_size"] = (18, 16)
	return (settings)

def other_settings(field, settings):
    settings = check_graph_size(field, settings)
    settings["steps_between_nodes"] = 5
    settings["repeat"] = False
    settings["link_color"] = "#101010"
    settings["used"] = ['#F7C59F', '#5A5a86', '#7CEA9C', '#55D6BE', '#2E5EAA', '#00C9FF', '#2A324B', '#F6C0D0', '#B8E1FF', '#808D8E', '#202030']
    settings["text_color"] = "#EEEEEE"
    settings["background_color"] = "#15202b"
    settings["node_color"] = "#282828"
    settings["ant_colors_list"] = "#15B6B6"
    settings["labels"] = dict([(field.start, 'START'), (field.end, 'END')])
    settings["interval"] = 20
    return(settings)

def change_speed(settings, args):
	if (args == '--slow'):
		settings['steps_between_nodes'] = 50
	elif (args == '--fast'):
		settings['steps_between_nodes'] = 5
	return (settings)

def get_settings(field, args):
    settings = {}
    print(args)
    if (check_args(args, '--slow') or check_args(args, '--fast')):
        settings = change_speed(settings, args)
    else:
        settings = other_settings(field, settings)
    return (settings)

def draw_node(data, name, color, size):
    node_list = []
    node_list.append(name)
    node = nx.draw_networkx_nodes(
        data['g'],
        data['pos'],
        nodelist = node_list,
        node_color = color,
        node_size = size)
    node.set_edgecolor('#000000')
    return(node)

def draw_nodes(data, settings):
    for name in data['field'].nodes:
        if (name == data['field'].start or name == data['field'].end):
            draw_node(data, name, settings['node_color'], settings['node_size'] * 2.5)
        else:
            draw_node(data, name, settings['node_color'], settings['node_size'])
        for i, path in enumerate(data['field'].used_nodes):	
            for node in path:
                draw_node(data, node, settings['used'][i], settings['node_size'])

def draw_ant(position, color, settings):
	ant = plt.plot([position[0]], [position[1]],
				   color=color, marker='.', markersize=settings["markersize"])
	return (ant)
