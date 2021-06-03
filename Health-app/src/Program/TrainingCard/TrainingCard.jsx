import React from 'react';
import './TrainingCard.css'
import Icon from '@mdi/react';
import {
    Subtitle2,
    Caption,
    Card
} from 'ui-neumorphism';

class Training extends React.Component {
    render() {
        return (
            <Card
                elevation={2}
                dark={false}
                className='card'
            >
                <Card
                    flat
                    className="icon"
                >
                    <Icon path={this.props.icon} size={1} color='var(--primary)'></Icon>
                </Card>
                <Subtitle2>{this.props.title}</Subtitle2>
                <Subtitle2 style={{ marginBottom: '10px' }}>{this.props.subtitle}</Subtitle2>
                <Caption secondary>{this.props.progress}</Caption>
            </Card>
        )
    }
}

export default Training;
