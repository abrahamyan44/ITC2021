import React from 'react';
import {
    H6,
    Card,
    Caption
} from 'ui-neumorphism';

class SimpleNotification extends React.Component {
    render () {
        const {dark, title, content} = this.props;
        return (
            <Card dark = {dark} height={60}>
                <H6 dark = {dark} style={{display: 'flex', marginLeft: '10px'}}>{title}</H6>
                <Caption secondary dark = {dark} style={{textAlign: 'left', marginLeft: '20px'}}>{content}</Caption>
            </Card>
        )
    }
}

export default SimpleNotification;