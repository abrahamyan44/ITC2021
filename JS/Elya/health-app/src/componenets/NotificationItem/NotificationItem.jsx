import React from 'react';
import { Card, ListItem } from 'ui-neumorphism';
import './NotificationItem.css';

function NatificationItem (props) {
    return(
        <>
            <Card
              flat
              width={300}
              className='d-flex align-center justify-center flex-wrap'
            >
              <ListItem
                link
                active
                title={props.title}
                subtitle={props.subtitle}
              />
            </Card>
        </>
    )
}

export default NatificationItem;