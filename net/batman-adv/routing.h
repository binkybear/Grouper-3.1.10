/*
 * Copyright (C) 2007-2011 B.A.T.M.A.N. contributors:
 *
 * Marek Lindner, Simon Wunderlich
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 *
 */

#ifndef _NET_BATMAN_ADV_ROUTING_H_
#define _NET_BATMAN_ADV_ROUTING_H_

void slide_own_bcast_window(struct hard_iface *hard_iface);
void receive_bat_packet(const struct ethhdr *ethhdr,
			struct batman_packet *batman_packet,
			const unsigned char *tt_buff,
			struct hard_iface *if_incoming);
void update_routes(struct bat_priv *bat_priv, struct orig_node *orig_node,
		   struct neigh_node *neigh_node);
int route_unicast_packet(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_icmp_packet(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_unicast_packet(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_ucast_frag_packet(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_bcast_packet(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_vis_packet(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_bat_packet(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_tt_query(struct sk_buff *skb, struct hard_iface *recv_if);
int recv_roam_adv(struct sk_buff *skb, struct hard_iface *recv_if);
struct neigh_node *find_router(struct bat_priv *bat_priv,
			       struct orig_node *orig_node,
			       const struct hard_iface *recv_if);
void bonding_candidate_del(struct orig_node *orig_node,
			   struct neigh_node *neigh_node);

#endif /* _NET_BATMAN_ADV_ROUTING_H_ */
